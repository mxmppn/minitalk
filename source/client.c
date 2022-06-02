/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:28:30 by mpepin            #+#    #+#             */
/*   Updated: 2022/06/02 16:59:05 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

// The chad binary sender to the chad signal receiver :
// Send a signal (SIGUSR1 or SIGUSR2, representing binary 0 or 1)
// to the "ue_pid" process ;
// with a delay of n microseconds, to fix the lag issue.
// It starts by the most significant bit to the least one
void	send_binary_to_serv(int nbr, int ue_pid)
{
	int	byte;

	byte = 0;
	while (byte < 8)
	{
		if ((nbr & 0x80) == 0)
			kill(ue_pid, SIGUSR1);
		else
			kill(ue_pid, SIGUSR2);
		nbr <<= 1;
		byte++;
		usleep(100);
	}
	return ;
}

// The main takes the PID of
// the process who you want to communicate with as arg1
// and the message u want to send as arg2, 3, ..., n.

// After the arg tests, it extracts the message and send
// it char by char to send_binary_to_serv()
int	main(int ac, char **av)
{
	pid_t	ue_pid;
	int		i;
	int		test;

	if (ac != 3)
	{
		printf("[ARG NBR ERROR] : 2 arguments needed : PID and String\n");
		return (-1);
	}
	if (check_pid_fmt(av[1]) == -1)
	{
		printf("[ARG TYPE ERROR] : Wrong PID format\n");
		return (-1);
	}
	ue_pid = str_to_int(av[1]);
	i = 0;
	printf("PID=%d\n", ue_pid);
	while (av[2][i])
	{
		test = av[2][i];
		send_binary_to_serv(test, ue_pid);
		i++;
		usleep(100);
	}
	return (0);
}

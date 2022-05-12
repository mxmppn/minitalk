/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:28:30 by mpepin            #+#    #+#             */
/*   Updated: 2022/05/09 17:44:31 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// The chad binary sender to the chad signal receiver :
// Send a signal (SIGUSR1 or SIGUSR2, representing binary 0 or 1)
// to the "ue_pid" process ;
// with a delay of 1/10th of a millisecond, to fix the lag issue
void	send_binary_to_serv(int nbr, int ue_pid)
{
	long long	binary_value;
	int			byte;

	binary_value = 0;
	byte = 0;
	while (byte < 8)
	{
		if (nbr % 2 == 0)
		{
			kill(ue_pid, SIGUSR1);
			printf("sent=0\n");
		}
		else
		{
			kill(ue_pid, SIGUSR2);
			printf("sent=1\n");
		}
		nbr /= 2;
		byte++;
		usleep(1000);
		// while (!signal_receive_test())
		// 	usleep(100);
	}
	printf("END_OF_BYTE\n");
	return ;
}

void	initiate_handshake(int ue_pid, int trust)
{
	kill(ue_pid, SIGUSR1);
	pause();
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
		exit(EXIT_FAILURE);
	}
	if (is_an_int(av[1]) == -1)
	{
		printf("[ARG TYPE ERROR] : Wrong PID format\n");
		exit(EXIT_FAILURE);
	}
	ue_pid = ft_atoi(av[1]);
	i = 0;
	printf("PID=%d\n", ue_pid);
	while (av[2][i])
	{
		test = av[2][i];
		send_binary_to_serv(test, ue_pid);
		i++;
	}
	return (0);
}

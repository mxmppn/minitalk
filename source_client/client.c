/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:28:30 by mpepin            #+#    #+#             */
/*   Updated: 2022/06/03 14:54:11 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

// The chad binary sender :
// Has the role of sending the (nbr) character to the "ue_pid" process,
// using SIGUSR1 or SIGUSR2, representing respectivly bits of 0 or 1.

// It send (nbr) as a byte, bits by bits, by using a bit shift comparaison
// with 10000000(2) to send it from the most significant bit to the least one.
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
		usleep(150);
	}
	return ;
}

// The main takes the PID of the process who you want to communicate
// with as (arg1)
// and the message u want to send as arg2.

// After the arg tests, it extracts the message (arg2) and send
// it char by char to send_binary_to_serv()
int	main(int ac, char **av)
{
	pid_t	ue_pid;
	int		i;
	int		char_to_send;

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
		char_to_send = av[2][i];
		send_binary_to_serv(char_to_send, ue_pid);
		i++;
		usleep(50);
	}
	return (0);
}

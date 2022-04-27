/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:40:51 by mpepin            #+#    #+#             */
/*   Updated: 2022/04/27 15:12:32 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	my_handler(int signum)
{
	if (signum == SIGUSR1)
		printf("0\n");
	if (signum == SIGUSR2)
		printf("1\n");
	return ;
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac != 1)
	{
		printf("[ARG NBR ERROR] : 0 argument needed\n");
		exit(EXIT_FAILURE);
	}
	server_pid = getpid();
	if (server_pid)
		printf("[SUCCESS] : Server opened\nCurrent PID=%d\n", server_pid);
	while (667)
	{
		signal(SIGUSR1, my_handler);
		signal(SIGUSR2, my_handler);
	}
	return (0);
}

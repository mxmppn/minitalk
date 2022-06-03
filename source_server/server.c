/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:40:51 by mpepin            #+#    #+#             */
/*   Updated: 2022/06/03 15:13:11 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

// The chad signal receiver/handler :
// Called when any SIGUSR1 or SIGUSR2 is received by the main, 
// it has the role of building the decimal (my_char),
// using the signals SIGUSR1 or SIGUSR2

// It works on a base of a byte : When a signal is received,
// it multiplies (my_char) by 2; if its SIGUSR1 then adds 0 and if its 
// SIGUSR2 then adds 1 (arithmetical construction of the byte).
// Every 8 calls, it will print the char corresponding to the decimal
// value of (my_char) and reset (my_char) to 0.
// If a signal from a different PID is received, it resets (my_char), to 
// avoid parasit bit shifting.  
void	my_handler(int signum, siginfo_t *info, void *context)
{
	static int		count = 7;
	static int		my_char = 0;
	static pid_t	g_client_pid = 0;

	(void) *context;
	if (info->si_pid != g_client_pid)
	{
		my_char = 0;
		count = 7;
		g_client_pid = info->si_pid;
	}
	my_char = my_char * 2;
	if (signum == SIGUSR2)
		my_char = my_char + 1;
	count--;
	if (count == -1)
	{
		write(1, &my_char, 1);
		my_char = 0;
		count = 7;
	}
	return ;
}

// The main displays the PID of himself when lauched, after all
// the arg tests

// Then it will listen for the two signals SIGUSR1 or SIGUSR2,
// and call my_handler when received (infinite loop)
int	main(int ac, char **av)
{
	pid_t				server_pid;
	struct sigaction	sa;

	(void) **av;
	if (ac != 1)
	{
		printf("[ARG NBR ERROR] : 0 argument needed\n");
		exit(EXIT_FAILURE);
	}
	server_pid = getpid();
	if (server_pid)
		printf("[SUCCESS] : Server opened\nCurrent PID=%d\n", server_pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = my_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (667)
		pause();
	return (0);
}

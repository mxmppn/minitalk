/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:40:51 by mpepin            #+#    #+#             */
/*   Updated: 2022/05/03 15:38:29 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Has the role of resetting to {0, 0, 0, 0, 0, 0, 0, 0} an "int	int_tab[8]"
int	*reset_binary_tab(int *int_tab)
{
	int	count;

	count = 0;
	while (count < 8)
	{
		int_tab[count] = 0;
		count ++;
	}
	return (int_tab);
}

// takes the tab of int, which represent the binary value (conventionnal order)
// of the int wanted to be send as the char
char	convert_to_char(int *int_tab)
{
	char	c;
	int		count;
	int		byte;

	count = 7;
	byte = 1;
	while (count >= 0)
	{
		c = (int)c + (byte * int_tab[count]);
		byte *= 2;
		count--;
	}
	return (c);
}

// The chad signal receiver/handler :
// Called when any SIGUSR1 or SIGUSR2 is received by the main, 
// it will creates at first call an int tab_int[8], and then fill it with
// the value of each bits corresponding to the signal received
// (0 for SIGUSR1, 1 for SIGUSR2).

// Every 8 calls, it will print the char corresponding to the decimal
// value of the byte stocked in the tab_int[8], then reset it to be 0 filled 
void	my_handler(int signum)
{
	static int	count = 7;
	static int	binary_int[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	char		byte_to_char;

	byte_to_char = 0;
	if (signum == SIGUSR1)
	{
		// write(1, "0\n", 2);
		binary_int[count] = 0;
	}
	else if (signum == SIGUSR2)
	{
		// write(1, "1\n", 2);
		binary_int[count] = 1;
	}
	count--;
	if (count == -1)
	{
		byte_to_char = convert_to_char(binary_int);
		write(1, &byte_to_char, 1);
		reset_binary_tab(binary_int);
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
	pid_t	server_pid;
	int		count;

	if (ac != 1)
	{
		printf("[ARG NBR ERROR] : 0 argument needed\n");
		exit(EXIT_FAILURE);
	}
	server_pid = getpid();
	count = 0;
	if (server_pid)
		printf("[SUCCESS] : Server opened\nCurrent PID=%d\n", server_pid);
	while (667)
	{
		signal(SIGUSR1, my_handler);
		signal(SIGUSR2, my_handler);
		usleep
	}
	return (0);
}

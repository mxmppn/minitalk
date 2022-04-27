/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:28:30 by mpepin            #+#    #+#             */
/*   Updated: 2022/04/27 18:28:00 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_space(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	is_an_int(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57) && !(i == 0 && str[i] == '-'))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	moins;
	int	result;

	i = 0;
	moins = 1;
	result = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			moins *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * moins);
}

void	send_binary_to_serv(int nbr, int ue_pid)
{
	long long	binary_value;
	int			byte;

	binary_value = 0;
	byte = 8;
	while (byte > 0)
	{
		if (nbr % 2 == 0)
		{
			printf("i send 0\n");
			kill(ue_pid, SIGUSR1);
		}
		else
		{
			printf("i send 1\n");
			kill(ue_pid, SIGUSR2);
		}
		nbr /= 2;
		byte--;
	}
	return ;
}

int	main(int ac, char **av)
{
	pid_t	ue_pid;
	int		test;

	if (ac < 3)
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
	test = atoi(av[2]);
	printf("TEST=%d\n", test);
	send_binary_to_serv(test, ue_pid);
	return (0);
}

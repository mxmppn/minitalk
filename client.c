/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:28:30 by mpepin            #+#    #+#             */
/*   Updated: 2022/04/27 16:05:10 by mpepin           ###   ########lyon.fr   */
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

int	is_number(char *str)
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

int	convert_to_binary(int nbr)
{
	int	binary_value;
	int	poids;

	binary_value = 0;
	poids = 1;
	if (nbr <= 1)
		return (nbr);
	while (nbr > 0)
	{
		binary_value += ((nbr % 2) * (poids));
		nbr /= 2;
		poids *= 10;
	}
	return (binary_value);
}

int	main(int ac, char **av)
{
	pid_t	ue_pid;

	if (ac < 3)
	{
		printf("[ARG NBR ERROR] : 2 arguments needed : PID and String\n");
		exit(EXIT_FAILURE);
	}
	if (is_number(av[1]) == -1)
	{
		printf("[ARG TYPE ERROR] : Wrong PID format\n");
		exit(EXIT_FAILURE);
	}
	ue_pid = ft_atoi(av[1]);
	if (strcmp(av[2], "oui") == 0)
		kill(ue_pid, SIGUSR1);
	if (strcmp(av[2], "non") == 0)
		kill(ue_pid, SIGUSR2);
	return (0);
}

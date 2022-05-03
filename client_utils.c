/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:27:14 by mpepin            #+#    #+#             */
/*   Updated: 2022/05/03 15:29:48 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// pretty self-explanatory, isn't it ?
int	is_space(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

// pretty self-explanatory, isn't it ?
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

// classic str to int, 42 sauced
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

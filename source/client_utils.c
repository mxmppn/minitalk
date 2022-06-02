/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:27:14 by mpepin            #+#    #+#             */
/*   Updated: 2022/06/02 13:37:16 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/minitalk.h"

// Pretty self-explanatory, isn't it ?
// Check if the PID is in good format : only numbers.
// Return 0 if str is only numbers, and -1 if not.
int	check_pid_fmt(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (-1);
		i++;
	}
	return (0);
}

// Classic str to int, (not atoi tho, to secure the PID format).
// Return the int that corresponds to the str.
int	str_to_int(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}

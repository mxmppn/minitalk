/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:39:11 by mpepin            #+#    #+#             */
/*   Updated: 2022/01/12 16:24:57 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_fmt_s(va_list params, int *char_nbr)
{
	char	*str;
	int		i;

	str = va_arg(params, char *);
	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*char_nbr) += 6;
		return ;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		(*char_nbr)++;
		i++;
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:58:30 by mpepin            #+#    #+#             */
/*   Updated: 2021/12/29 16:23:10 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_fmt(char c, va_list params, int *char_nbr)
{
	if (c == 'c')
		return (ft_print_fmt_c(params, char_nbr));
	else if (c == 's')
		return (ft_print_fmt_s(params, char_nbr));
	else if (c == 'p')
		return (ft_print_fmt_p(params, char_nbr));
	else if (c == 'd')
		return (ft_print_fmt_d(params, char_nbr));
	else if (c == 'i')
		return (ft_print_fmt_i(params, char_nbr));
	else if (c == 'u')
		return (ft_print_fmt_u(params, char_nbr));
	else if (c == 'x')
		return (ft_print_fmt_x(params, char_nbr));
	else if (c == 'X')
		return (ft_print_fmt_xx(params, char_nbr));
	else if (c == '%')
		return (ft_print_fmt_percent(char_nbr));
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:29:50 by mpepin            #+#    #+#             */
/*   Updated: 2021/12/29 17:02:44 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_fmt_c(va_list params, int *char_nbr)
{
	char	ch;

	ch = (char)(va_arg(params, int));
	write(1, &ch, 1);
	(*char_nbr)++;
	return ;
}

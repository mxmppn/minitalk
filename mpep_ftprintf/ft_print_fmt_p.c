/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:59:03 by mpepin            #+#    #+#             */
/*   Updated: 2021/12/29 17:24:45 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_base16(unsigned long long n, int *char_nbr, char *base16)
{
	write(1, &base16[n], 1);
	(*char_nbr)++;
	return ;
}

static void	ft_putnbr_base16(unsigned long long n, int *char_nbr, char *base16)
{
	unsigned long long	nb;

	nb = n;
	if (nb > 15)
	{
		ft_putnbr_base16(nb / 16, char_nbr, base16);
		ft_putnbr_base16(nb % 16, char_nbr, base16);
	}
	else
		ft_putchar_base16(nb, char_nbr, base16);
	return ;
}

void	ft_print_fmt_p(va_list params, int *char_nbr)
{
	unsigned long long	pointer;
	char				base16[17];
	int					i;

	pointer = (unsigned long long)va_arg(params, unsigned long long);
	i = 0;
	while (i < 10)
	{
		base16[i] = '0' + i;
		i++;
	}
	while (i < 16)
	{
		base16[i] = 87 + i;
		i++;
	}
	base16[i] = 0;
	write(1, "0x", 2);
	(*char_nbr) = (*char_nbr) + 2;
	ft_putnbr_base16(pointer, char_nbr, base16);
	return ;
}

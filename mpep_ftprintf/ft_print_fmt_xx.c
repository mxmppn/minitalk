/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_XX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:58:41 by mpepin            #+#    #+#             */
/*   Updated: 2021/12/29 17:26:22 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_base16(unsigned int n, int *char_nbr, char *base16)
{
	write(1, &base16[n], 1);
	(*char_nbr)++;
	return ;
}

static void	ft_putnbr_base16(unsigned int n, int *char_nbr, char *base16)
{
	unsigned int	nb;

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

void	ft_print_fmt_xx(va_list params, int *char_nbr)
{
	unsigned int		nbr;
	char				base16[17];
	int					i;

	nbr = (unsigned int)(va_arg(params, unsigned int));
	i = 0;
	while (i < 10)
	{
		base16[i] = '0' + i;
		i++;
	}
	while (i < 16)
	{
		base16[i] = 55 + i;
		i++;
	}
	base16[i] = 0;
	ft_putnbr_base16(nbr, char_nbr, base16);
	return ;
}

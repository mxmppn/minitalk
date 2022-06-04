/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:59:15 by mpepin            #+#    #+#             */
/*   Updated: 2021/12/29 16:18:42 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	starting_power10(unsigned int n)
{
	unsigned long long		power10;

	power10 = 1;
	while (n / power10 >= 10)
	{
		power10 *= 10;
	}
	return (power10);
}

static void	ft_putdigit_fd(unsigned int n, int fd, int *char_nbr)
{
	char	my_digit;

	my_digit = 48 + n;
	write(fd, &my_digit, 1);
	(*char_nbr)++;
}

static void	ft_putnbr_fd(unsigned int n, int fd, int *char_nbr)
{
	unsigned long long	power10;
	int					digit;
	unsigned int		nbr;

	nbr = n;
	power10 = starting_power10(n);
	digit = nbr / power10;
	ft_putdigit_fd(digit, fd, char_nbr);
	nbr = nbr - (power10 * digit);
	power10 /= 10;
	while (power10 > 0)
	{
		digit = nbr / power10;
		ft_putdigit_fd(digit, fd, char_nbr);
		nbr = nbr - (power10 * digit);
		power10 /= 10;
	}
}

void	ft_print_fmt_u(va_list params, int *char_nbr)
{
	unsigned int	nbr;

	nbr = (unsigned int)va_arg(params, unsigned int);
	ft_putnbr_fd(nbr, 1, char_nbr);
	return ;
}

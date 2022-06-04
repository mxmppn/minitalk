/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:48:08 by mpepin            #+#    #+#             */
/*   Updated: 2021/12/29 16:24:25 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	starting_power10(int n)
{
	long long				nbr;
	unsigned long long		power10;

	nbr = n;
	power10 = 1;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr / power10 >= 10)
	{
		power10 *= 10;
	}
	return (power10);
}

static void	ft_putdigit_fd(int n, int fd, int *char_nbr)
{
	char	my_digit;

	my_digit = 48 + n;
	write(fd, &my_digit, 1);
	(*char_nbr)++;
}

static void	ft_putnbr_fd(int n, int fd, int *char_nbr)
{
	unsigned long long	power10;
	long long			nbr;
	int					digit;

	power10 = starting_power10(n);
	nbr = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		(*char_nbr)++;
		nbr = -nbr;
	}
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

void	ft_print_fmt_i(va_list params, int *char_nbr)
{
	int	nbr;

	nbr = (int)(va_arg(params, int));
	ft_putnbr_fd(nbr, 1, char_nbr);
	return ;
}

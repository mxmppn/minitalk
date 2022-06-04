/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:40:37 by mpepin            #+#    #+#             */
/*   Updated: 2022/01/12 16:32:47 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_non_fmt(char c, int *char_nbr)
{
	write(1, &c, 1);
	(*char_nbr)++;
}

int	ft_printf(const char *fmt, ...)
{
	int				i;
	int				char_nbr;
	unsigned int	is_percent;
	va_list			params;

	i = 0;
	char_nbr = 0;
	is_percent = 0;
	va_start(params, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			ft_print_fmt(fmt[i], params, &char_nbr);
		}
		else
			ft_print_non_fmt(fmt[i], &char_nbr);
		i++;
	}
	va_end(params);
	return (char_nbr);
}

/* ************************************************************************ */
/*																			*/
/*																			*/
/*									TESTS									*/
/*																			*/
/*																			*/
/* ************************************************************************ */

// int	main(void)
// {
// 	void	*point;
// 	int		nbr_of_char;
// 	int		nbr_of_char_print;

// 	point = NULL;
// 	ft_printf("ok ceci est un test\n");
// 	ft_printf("");
// 	nbr_of_char = ft_printf("%c %s %p %d %i %u %x %X %%", 'c', "test", point,
// 			-2147483648, 2147483647, 4294967295, 2147483647, 1010101010);
// 	printf("\n");
// 	nbr_of_char_print = printf("%c %s %p %d %i %u %x %X %%", 'c', "test", point,
// 			-2147483648, 2147483647, 4294967295, 2147483647, 1010101010);
// 	printf("\nMINE : %d ; REAL : %d\n", nbr_of_char, nbr_of_char_print);
// 	return (0);
// }

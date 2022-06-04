/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:52:11 by mpepin            #+#    #+#             */
/*   Updated: 2022/01/05 20:25:11 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ************************************************************************ */
/*																			*/
/*																			*/
/*								LIBRAIRIES									*/
/*																			*/
/*																			*/
/* ************************************************************************ */

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

/* ************************************************************************ */
/*																			*/
/*																			*/
/*								FUNCTIONS									*/
/*																			*/
/*																			*/
/* ************************************************************************ */

int			ft_printf(const char *fmt, ...);
void		ft_print_fmt(char c, va_list params, int *char_nbr);
void		ft_print_fmt_c(va_list params, int *char_nbr);
void		ft_print_fmt_d(va_list params, int *char_nbr);
void		ft_print_fmt_i(va_list params, int *char_nbr);
void		ft_print_fmt_p(va_list params, int *char_nbr);
void		ft_print_fmt_s(va_list params, int *char_nbr);
void		ft_print_fmt_u(va_list params, int *char_nbr);
void		ft_print_fmt_x(va_list params, int *char_nbr);
void		ft_print_fmt_xx(va_list params, int *char_nbr);
void		ft_print_fmt_percent(int *char_nbr);

#endif
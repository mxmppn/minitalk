/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:23:43 by mpepin            #+#    #+#             */
/*   Updated: 2022/05/08 23:48:14 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */
/*~IM JUST A SEPARATOR, DON'T MIND I ONLY EXIST FOR THIS REASON, LIFE IS PAIN~*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */

/* ************************************************************************ */
/*																			*/
/*																			*/
/*								LIBRAIRIES									*/
/*																			*/
/*																			*/
/* ************************************************************************ */

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>

/* ************************************************************************ */
/*																			*/
/*																			*/
/*								STRUCTURES									*/
/*																			*/
/*																			*/
/* ************************************************************************ */

/*						THIS IS PRETTY EMPTY, ISN'T IT ?					*/

/* ************************************************************************ */
/*																			*/
/*																			*/
/*								FUNCTIONS									*/
/*																			*/
/*																			*/
/* ************************************************************************ */

// int			ft_printf(const char *fmt, ...);
int			ft_atoi(const char *str);
int			is_space(char c);
int			is_number(char *str);
int			is_an_int(char *str);
void		send_binary_to_serv(int nbr, int ue_pid);
int			*reset_binary_tab(int *int_tab);
char		convert_to_char(int *int_tab);
void		my_handler(int signum);

/* ************************************************************************ */
/*																			*/
/*																			*/
/*								VARIABLES									*/
/*																			*/
/*																			*/
/* ************************************************************************ */

static volatile int	client_pid;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */
/*~IM JUST A SEPARATOR, DON'T MIND I ONLY EXIST FOR THIS REASON, LIFE IS PAIN~*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */

#endif
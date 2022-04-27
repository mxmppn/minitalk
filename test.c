/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:43:15 by mpepin            #+#    #+#             */
/*   Updated: 2022/04/27 16:28:32 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long long	convert_to_binary(int nbr)
{
	long long	binary_value;
	long long	poids;

	binary_value = 0;
	poids = 1;
	if (nbr <= 1)
		return (nbr);
	while (nbr > 0)
	{
		binary_value += ((nbr % 2) * (poids));
		nbr /= 2;
		poids *= 10;
	}
	return (binary_value);
}

int	main(int ac, char **av)
{
	int	nbr;

	nbr = atoi(av[1]);
	printf("** -- ** base10 =%d ; base2 =%lld ** -- **\n", nbr, convert_to_binary(nbr));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:51:10 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/20 16:39:49 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		init(void)
{
	char	b[256];

	ft_putstrcolor("Commencer ? (", "0");
	ft_putstrcolor("Y", "32");
	ft_putstrcolor("/", "0");
	ft_putstrcolor("N", "31");
	ft_putstrcolor(")\n", "0");
	while (1)
	{
		if (read(0, b, 256) > 2 || b[1] != '\n')
			ft_putstrcolor("Tape Y ou N !\n", "1;31");
		else if (b[0] != 'Y' && b[0] != 'N' && b[0] != 'y' && b[0] != 'n')
			ft_putstrcolor("Tape Y ou N !\n", "1;31");
		else
			break ;
	}
	if (b[0] == 'Y' || b[0] == 'y')
	{
		ft_putstrcolor("Vous commencez !\n", "32");
		return (1);
	}
	else
		ft_putstrcolor("L'ordinateur commencera !\n", "31");
	return (2);
}

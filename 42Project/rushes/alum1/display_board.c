/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <framel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:49:07 by framel            #+#    #+#             */
/*   Updated: 2015/12/20 16:21:17 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static void		ft_display_line(int nb, int max)
{
	int		i;

	i = 0;
	while (i < (max - nb) / 2)
	{
		write(1, " ", 1);
		i++;
	}
	while (nb--)
	{
		write(1, "|", 1);
	}
	write(1, "\n", 1);
}

int				longgest_line(int *nb)
{
	int		max;
	int		i;

	i = 0;
	max = 0;
	while (nb[i])
	{
		if (nb[i] > max)
			max = nb[i];
		i++;
	}
	return (max);
}

void			ft_display_board(int *nb, int l)
{
	int		i;
	int		max;

	i = 0;
	max = longgest_line(nb);
	while (i < l)
	{
		ft_display_line(nb[i], max);
		i++;
	}
}

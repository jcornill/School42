/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:28:14 by jcornill          #+#    #+#             */
/*   Updated: 2016/04/01 17:57:07 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		place_piece(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	collide;

	j = -1;
	collide = 0;
	while (++j < data->piece->heigth)
	{
		i = -1;
		while (++i < data->piece->width)
		{
			if (i + x >= data->grid->width || j + y >= data->grid->heigth)
				return (0);
			if (data->grid->grid[(i + x) + (j + y) * data->grid->width] != 0)
				if (data->piece->piece[i + j * data->piece->width] != 0)
				{
					if (data->piece->piece[i + j * data->piece->width] ==
					data->grid->grid[(i + x) + (j + y) * data->grid->width])
						collide++;
					else
						return (0);
				}
		}
	}
	return (collide == 1);
}

void	process(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (place_piece(data, i, j) == 0)
	{
		i++;
		if (i >= data->grid->width)
		{
			i = 0;
			j++;
		}
		if (j >= data->grid->heigth)
		{
			i = 0;
			j = 0;
			break ;
		}
	}
	ft_putnbr(j);
	ft_putchar(' ');
	ft_putnbr(i);
	ft_putchar('\n');
}

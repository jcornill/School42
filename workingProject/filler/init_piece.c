/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 13:41:59 by jcornill          #+#    #+#             */
/*   Updated: 2016/04/01 14:49:29 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_piece(char *str, t_piece *piece, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	piece->piece = ft_memalloc(piece->heigth * piece->width + 1);
	while (j < piece->heigth && get_next_line(0, &str) > 0)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '.')
				piece->piece[i + j * piece->width] = 0;
			else if (data->player == 1)
				piece->piece[i + j * piece->width] = 1;
			else if (data->player == 2)
				piece->piece[i + j * piece->width] = 2;
			i++;
		}
		j++;
	}
}

t_piece	*init_piece(char *str, t_data *data)
{
	t_piece	*piece;
	int		i;

	piece = ft_memalloc(sizeof(t_piece));
	i = 0;
	if (get_next_line(0, &str) > 0)
	{
		while (!ft_isdigit(str[i]))
			i++;
		piece->heigth = ft_atoi(&str[i]);
		while (ft_isdigit(str[i]))
			i++;
		i++;
		piece->width = ft_atoi(&str[i]);
	}
	set_piece(str, piece, data);
	return (piece);
}

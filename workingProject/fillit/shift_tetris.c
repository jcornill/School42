/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 21:41:56 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/03 17:52:41 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		push_tetris_left(char **tetris, int i, int j)
{
	while (i < 4)
	{
		if (tetris[i][0] == '.')
			j++;
		if (j == 4)
		{
			i = -1;
			while (++i < 4)
			{
				j = -1;
				while (++j < 4)
					tetris[j][i] = tetris[j][i + 1];
			}
			i = -1;
			while (++i < 4)
				tetris[i][3] = '.';
			i = -1;
			j = 0;
		}
		i++;
	}
}

static void		push_tetris_top(char **tetris, int i, int j)
{
	while (i < 4)
	{
		if (tetris[0][i] == '.')
			j++;
		if (j == 4)
		{
			i = -1;
			while (++i < 3)
			{
				j = -1;
				while (++j < 4)
					tetris[i][j] = tetris[i + 1][j];
			}
			i = -1;
			while (++i < 4)
				tetris[3][i] = '.';
			i = -1;
			j = 0;
		}
		i++;
	}
}

int				shift_tetris(char **tetris)
{
	push_tetris_left(tetris, 0, 0);
	push_tetris_top(tetris, 0, 0);
	if (!check_tetriminos(tetris))
		return (0);
	return (1);
}

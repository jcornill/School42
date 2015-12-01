/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 22:20:49 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/01 23:02:28 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_in_range(int i, int j)
{
	if (i < 0 || j < 0)
		return (0);
	if (i > 3 || j > 3)
		return (0);
	return (1);
}

static int	check_neighbourg(char **tetris, int i, int j)
{
	int	memi;
	int memj;

	memi = i + 1;
	i -= 1;
	while (i < memi)
	{
		if (is_in_range(i, j))
		{
			if (tetris[i][j] == '#')
				return (1);
		}
		i += 2;
	}
	memj = j + 1;
	j -= 1;
	while (j < memj)
	{
		if (is_in_range(memi - 1, j))
		{
			if (tetris[memi - 1][j] == '#')
				return (1);
		}
		j += 2;
	}
	return (0);
}

int			check_tetriminos(char **tetris)
{
	int i;
	int j;
	int	k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetris[i][j] == '#')
			{
				k += check_neighbourg(tetris, i, j);
			}
			j++;
		}
		i++;
	}
	if (k == 3)
		return (1);
	return (0);
}

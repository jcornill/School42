/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:49:10 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/05 17:09:40 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "grid.h"

int				size_of_square(char **grid)
{
	int		max;
	int		i;
	int		j;

	max = 0;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] != '.' && (i > max || j > max))
				max = (i > j) ? i : j;
			j++;
		}
		i++;
	}
	return (max + 1);
}

t_coord			next_co(t_coord co)
{
	if (co.y == co.x - 1)
	{
		co.x = 0;
		co.y++;
	}
	else if (co.x == co.y)
	{
		co.y = 0;
		co.x++;
	}
	else if (co.y > co.x)
		co.x++;
	else
		co.y++;
	return (co);
}

int				is_all_tetris_placed(t_tetrimino *tet, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		if (!tet[i].is_placed)
			return (0);
	return (1);
}

void			comp_best(t_path *best, t_path *other, t_tetrimino *t, char **g)
{
	ft_strncat(other->path, &(t->letter), 1);
	if (best->square_size == -1 || other->square_size < best->square_size)
	{
		best->path = ft_strcpy(best->path, other->path);
		best->square_size = other->square_size;
	}
	free(other->path);
	other->path = NULL;
	remove_tetris_from_grid(t->letter, g);
	t->is_placed = 0;
}

t_path			fill_grid(char **grid, t_tetrimino *tetris, t_coord co, int n)
{
	int		i;
	t_path	best;
	t_path	other;

	best.square_size = -1;
	if (!(best.path = ft_strnew(n + 1)))
		return (best);
	if (grid[co.y][co.x] != '.')
		return (fill_grid(grid, tetris, next_co(co), n));
	if (is_all_tetris_placed(tetris, n))
	{
		best.square_size = size_of_square(grid);
		return (best);
	}
	i = -1;
	while (++i < n)
	{
		
		if (!tetris[i].is_placed && place_tetris_at(tetris[i], co, grid))
		{
			tetris[i].is_placed = 1;
			other = fill_grid(grid, tetris, next_co(co), n);
			comp_best(&best, &other, &tetris[i], grid);
		}
	}
	if (best.square_size == -1)
		return (fill_grid(grid, tetris, next_co(co), n));
	return (best);
}

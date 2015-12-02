/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:49:10 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/02 20:58:14 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "grid.h"

static int		size_of_square(char **grid)
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

static void		debug(char **grid, t_tetrimino tetris, t_coord co)
{
	for (int k = 0; grid[k]; k++)
	{
		printf("\n");
		for (int j = 0; grid[k][j]; j++)
			printf("%c", grid[k][j]);
	}
	printf("\nplace\n");
	print_tetris(tetris.map);
	printf("at %d:%d\n", co.y, co.x);
	printf("size of square %d\n", size_of_square(grid));
}

static t_coord	next_coord(t_coord co)
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
	printf("Next co %d:%d\n", co.y, co.x);
	return (co);
}

/*
**int		fill_grid(char **grid, int nbr_tetris, t_tetrimino *tetris, t_coord co)
**{
**	int		i;
**
**	i = 0;
**	while (grid[co.y][co.x] != '.')
**		co = next_coord(co);
**	while (i < nbr_tetris)
**	{
**		if (!tetris[i].is_placed && place_tetris_at(tetris[i], co, grid))
**		{
**			debug(grid, tetris[i], co);
**			tetris[i].is_placed = 1;
**			if (!fill_grid(grid, nbr_tetris, tetris, next_coord(co)))
**				return (0);
**		}
**		i++;
**	}
**	return (1);
**}
*/

int			is_all_tetris_placed(t_tetrimino *tet)
{
	int		i;

	i = -1;
	while (tet[++i])
		if (!tet[i].is_placed)
			return (0);
	return (1);
} 

int			fill_grid(char **grid, t_tetrimino *tetris, t_coord co, t_path *parent)
{
	int		i;
	t_path	child;
	t_path	best;

	child = *parent;
	if (grid[co.y][co.x] != '.')
		return (fill_grid(grid, tetris, next_co(co), &child));
	i = -1;
	if (is_all_tetris_placed(tetris))
		parent->square_size = size_of_square(grid);
	while (tetris[++i])
	{
		child = *parent;
		ft_strcat(child.path, &(tetris[i].letter));
		if (!tetris[i].is_placed && place_tetris_at(tetris[i], co, grid))
		{
			tetris[i].is_placed = 1;
			fill_grid(grid, tetris, next_co(co), &child);
			if (child.square_size < best.square_size)
				best = child;
			remove_tetris_from_grid(tetris[i].letter, grid);
			tetris[i].is_placed = 0;
		}
	}
	return (best.square_size);
}

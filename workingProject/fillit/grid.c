/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:39:03 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/03 17:58:13 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"

static void	shift_coord(t_coord *coord, t_tetrimino tetris)
{
	if (tetris.map[0][0] != '.')
		return ;
	else
	{
		if (tetris.map[0][1] == '#')
			coord->x -= 1;
		else
			coord->x -= 2;
	}
}

char		**create_grid(int nbr_tetris)
{
	char	**grid;
	int		line_parser;

	grid = (char **)malloc(sizeof(char *) * MAX_SIZE(nbr_tetris) + 1);
	if (grid == NULL)
		return (NULL);
	line_parser = 0;
	while (line_parser < MAX_SIZE(nbr_tetris))
	{
		grid[line_parser] = ft_strnew(MAX_SIZE(nbr_tetris) + 1);
		if (grid[line_parser] == NULL)
			return (NULL);
		ft_memset(grid[line_parser], '.', MAX_SIZE(nbr_tetris));
		line_parser++;
	}
	grid[MAX_SIZE(nbr_tetris)] = 0;
	return (grid);
}

void		free_grid(char **grid)
{
	int	line_parser;

	line_parser = 0;
	while (grid[line_parser] != NULL)
	{
		free(grid[line_parser]);
		line_parser++;
	}
	free(grid);
}

int			place_tetris_at(t_tetrimino tetris, t_coord c, char **grid)
{
	int	x;
	int	y;

	if (grid[c.y][c.x] != '.')
		return (0);
	shift_coord(&c, tetris);
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (grid[c.y + y][c.x + x] == '.' && tetris.map[y][x] != '.')
				grid[c.y + y][c.x + x] = tetris.letter;
			else if (grid[c.y + y][c.x + x] != '.' && tetris.map[y][x] != '.')
			{
				remove_tetris_from_grid(tetris.letter, grid);
				return (0);
			}
		}
	}
	return (1);
}

void		remove_tetris_from_grid(char letter, char **grid)
{
	int	y;
	int	x;

	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
			if (grid[y][x] == letter)
				grid[y][x] = '.';
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:49:10 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/03 01:33:00 by jcornill         ###   ########.fr       */
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

static void		debug(char **grid, t_tetrimino tetris, t_coord co)
{
    printf("\nplace\n");
    print_tetris(tetris.map);
    printf("at %d:%d\n", co.y, co.x);
    printf("size of square %d\n", size_of_square(grid));
	display_grid(grid);
	printf("\n");
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
	printf("Next co %d:%d\n", co.y, co.x);
	return (co);
}

int			is_all_tetris_placed(t_tetrimino *tet)
{
	int		i;

	i = -1;
	while (tet[++i].map != NULL)
		if (!tet[i].is_placed)
			return (0);
	return (1);
} 

t_path		fill_grid(char **grid, t_tetrimino *tetris, t_coord co, int n)
{
	int		i;
	t_path	child;
	t_path	best;
	t_path	other;

	child.square_size = -1;
    child.path = ft_strnew(27);
	best.square_size = -1;
	printf("-----------fill_grid----------\n");
	if (grid[co.y][co.x] != '.')
		return (fill_grid(grid, tetris, next_co(co), n));
	i = 0;
	if (is_all_tetris_placed(tetris))
	{
		printf("all tetris placed\n");
		child.square_size = -2;
		return (child);
	}
	while (i < n)
	{
		if (!tetris[i].is_placed && place_tetris_at(tetris[i], co, grid))
		{
			ft_strcat(child.path, &(tetris[i].letter));
			printf("%s\n", child.path);
			debug(grid, tetris[i], co);
			tetris[i].is_placed = 1;
			other = fill_grid(grid, tetris, next_co(co), n);
			if (best.square_size == -1 || (other.square_size < best.square_size && child.square_size != -2))
			{
				printf("NBest : %s\n", child.path);				
				best = child;
			}
//			if (best.square_size == -1 || (child.square_size < best.square_size && child.square_size > 0))
//			{
//				printf("%d:%d\n", child.square_size, best.square_size);
//				best = child;
//				printf("Best : %s\n", best.path);
//			}
			remove_tetris_from_grid(tetris[i].letter, grid);
			tetris[i].is_placed = 0;
		}
		i++;
	}
	//printf("Best : %s\n", best.path);
	return (best);
}

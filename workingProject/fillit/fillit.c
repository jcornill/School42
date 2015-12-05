/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 22:02:18 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/05 17:12:44 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "check_file.h"
#include "grid.h"
#include "libft.h"

int			main(int argc, char **argv)
{
	int			nbr_tetris;
	char		**grid;
	t_tetrimino	*tetris;
	t_coord		co;
	t_path		path;

	path.square_size = -1;
	path.path = ft_strnew(27);
	co.x = 0;
	co.y = 0;
	nbr_tetris = -1;
	if (argc != 2 || !(is_valid_file(argv[1])))
		write(1, "error\n", 6);
	else if (!(nbr_tetris = process_file(argv[1], 0, &tetris)))
		write(1, "error\n", 6);
	else
	{
		grid = create_grid(nbr_tetris);
		path = fill_grid(grid, tetris, co, nbr_tetris);
		ft_strrev(path.path);
		grid_from_str(path.path, grid, tetris, co);
		display_grid(grid);
		free_grid(grid);
	}
	return (0);
}

void		display_grid(char **grid)
{
	int		i;
	int		j;
	int		size;

	size = size_of_square(grid);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(grid[i][j]);
		ft_putchar('\n');
	}
}

void		grid_from_str(char *str, char **grid, t_tetrimino *t, t_coord co)
{
	int		i;

	if (is_all_tetris_placed(t,ft_strlen(str))  || *str == 0)
		return ;
	i = 0;
	while (t[i].letter != *str)
		i++;
	if (place_tetris_at(t[i], co, grid))
		str++;
	grid_from_str(str, grid, t, next_co(co));
}

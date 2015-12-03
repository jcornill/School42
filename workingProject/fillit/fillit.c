/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 22:02:18 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/03 00:58:57 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "check_file.h"
#include "grid.h"
#include "libft.h"

int		main(void)
{
	int			nbr_tetris;
	char 		**grid;
	t_tetrimino	*tetris;
	t_coord		co;
	t_path		path;

	path.square_size = -1;
	path.path = ft_strnew(27);
	co.x = 0;
	co.y = 0;
	nbr_tetris = -1;
	tetris = NULL;
	if (!(is_valid_file("sample.fillit")))
		printf("ERROR1\n");
	else if (!(nbr_tetris = process_file("sample.fillit", 0, &tetris)))
		printf("ERROR2\n");
	grid = create_grid(nbr_tetris);
	path = fill_grid(grid, tetris, co, nbr_tetris);
	grid_from_str(path.path, grid, tetris, co);
	display_grid(grid);
	free_grid(grid);
	return (0);
}

void	display_grid(char **grid)
{
	int		i;
	int 	j;
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

void	grid_from_str(char *str, char **grid, t_tetrimino *tetris, t_coord co)
{
	int		i;

	printf("%s\n", str);
	printf("Je construit ma petit grille please wait lettre : %c%d\n", *str, *str);
	if (is_all_tetris_placed(tetris) || *str == 0)
		return ;
	i = 0;
	while (tetris[i].letter != *str)
		i++;
	if (place_tetris_at(tetris[i], co, grid))
		str++;
	grid_from_str(str, grid, tetris, next_co(co));
}


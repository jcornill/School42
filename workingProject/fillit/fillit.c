/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 22:02:18 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/02 20:00:52 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "check_file.h"
#include "grid.h"

int		main(void)
{
	int			nbr_tetris;
	char 		**grid;
	t_tetrimino	*tetris;
	t_coord		co;

	co.x = 0;
	co.y = 0;
	nbr_tetris = -1;
	tetris = NULL;
	if (!(is_valid_file("sample.fillit")))
		printf("ERROR1\n");
	else if (!(nbr_tetris = process_file("sample.fillit", 0, &tetris)))
		printf("ERROR2\n");
	grid = create_grid(nbr_tetris);
	for (int i = 0; grid[i]; i++)
	{
		printf("\n");
		for (int j = 0; grid[i][j]; j++)
			printf("%c", grid[i][j]);
	}
	printf("\n\n");
	fill_grid(grid, nbr_tetris, tetris, co);
	for (int i = 0; grid[i]; i++)
    {
        printf("\n");
        for (int j = 0; grid[i][j]; j++)
            printf("%c", grid[i][j]);
    }
	free_grid(grid);
	return (0);
}

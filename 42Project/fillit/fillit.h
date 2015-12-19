/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:19:13 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/05 17:12:10 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#   include <stdio.h>
typedef struct	s_tetrimino
{
	char		**map;
	char		letter;
	char		is_placed;
}				t_tetrimino;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_path
{
	char		*path;
	int			square_size;
}				t_path;

int				get_nbr_tetriminos(char *file);
int				size_of_square(char **grid);
t_coord			next_co(t_coord co);
int				is_all_tetris_placed(t_tetrimino *tet, int n);
t_path			fill_grid(char **g, t_tetrimino *t, t_coord c, int n);
int				process_file(char *file, int i, t_tetrimino **tetris);
int				shift_tetris(char **tetris);
int				check_tetriminos(char **tetris);
void			display_grid(char **grid);
void			grid_from_str(char *s, char **g, t_tetrimino *t, t_coord c);
#endif

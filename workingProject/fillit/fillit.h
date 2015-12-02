/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:19:13 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/02 20:05:04 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ####      #
**           #
** ##        #
** ##        #
**
**  #   #   ###    #
** ###  ##   #    ##
**      #          #
**
** ###    ###
** #        #
**
** #       #
** #       #
** ##     ##
**
**   #    #
** ###    ###
**
** ##     ##
**  #     #
**  #     #
**
** ##    ##
**  ##  ##
**
**  #   #
** ##   ##
** #     #
**
*/

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#  include <stdio.h>

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

int				fill_grid(char **grid, int nbr_tetris, t_tetrimino *tetris, t_coord co);
int				process_file(char *file, int i, t_tetrimino **tetris);
int				shift_tetris(char **tetris);
int				check_tetriminos(char **tetris);
void	print_tetris(char **tetris);
#endif

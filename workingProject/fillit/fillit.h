/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:19:13 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/01 22:53:27 by jcornill         ###   ########.fr       */
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

typedef struct	s_tetriminos
{
	char		**tetriminos;
	char		letter;
}				t_tetriminos;

int				process_file(char *file, int i);
int				shift_tetris(char **tetris);
int				check_tetriminos(char **tetris);
void	print_tetris(char **tetris, int nbr);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:40:09 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/03 17:58:47 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# include "fillit.h"
# include "libft.h"
# define MAX_SIZE(NBR) NBR * 4

char		**create_grid(int nbr_tetris);
void		free_grid(char **grid);
int			place_tetris_at(t_tetrimino tetris, t_coord c, char **grid);
void		remove_tetris_from_grid(char letter, char **grid);

#endif

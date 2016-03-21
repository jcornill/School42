/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:07:56 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/21 14:24:46 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		*create_line(t_coord *start, t_coord *end, int cstart, int cend)
{
	t_line	*line;

	line = ft_memalloc(sizeof(t_line));
	line->start = start;
	line->end = end;
	line->color_start = cstart;
	line->color_end = cend;
	return (line);
}

t_coord		*create_coord(int x, int y)
{
	t_coord	*coord;

	coord = ft_memalloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	return (coord);
}

t_mlxwin	*create_win(int width, int height, char *name)
{
	t_mlxwin	*win;

	win = ft_memalloc(sizeof(t_mlxwin));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, width, height, name);
	return (win);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:00:24 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/21 15:32:51 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_mlxwin *win, t_line *line)
{
	int		dx;
	int		dy;
	int		x;
	int		dc;

	dx = line->end->x - line->start->x;
	dy = line->end->y - line->start->y;
	dc = line->color_end - line->color_start;
	x = line->start->x;
	while (x < line->end->x)
	{
		mlx_pixel_put(win->mlx, win->win, x, line->start->y + dy *
		(x - line->start->x) / dx, line->color_start + dc *
		(x - line->start->x) / dx);
		x++;
	}
}

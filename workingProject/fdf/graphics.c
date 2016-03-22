/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:00:24 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/22 17:03:29 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_mlxwin *win, t_line *line)
{
	int		dx;
	int		dy;
	int		x;
	char	*img;

	dx = line->end->x - line->start->x;
	dy = line->end->y - line->start->y;
	x = line->start->x;
	img = mlx_get_data_addr(win->img->img, &win->img->bpp,
	&win->img->sl, &win->img->end);
	while (x < line->end->x)
	{
		img[((x * 4) + (line->start->y + dy * (x - line->start->x) / dx)
		* win->width * 4)] = line->color_start->blue +
		(line->color_end->blue *(x - line->start->x) / dx);
		img[((x * 4) + (line->start->y + dy * (x - line->start->x) / dx)
		* win->width * 4) + 1] = line->color_start->green +
		(line->color_end->green * (x - line->start->x) / dx);
		img[((x * 4) + (line->start->y + dy * (x - line->start->x) / dx)
		* win->width * 4) + 2] = line->color_start->red +
		(line->color_end->red * (x - line->start->x) / dx);
		img[((x * 4) + (line->start->y + dy * (x - line->start->x) / dx)
		* win->width * 4) + 3] = line->color_start->alpha;
		x++;
	}
}

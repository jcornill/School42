/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:07:56 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/22 15:45:22 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		*create_line(t_coord *start, t_coord *end,
			t_color *cstart, t_color *cend)
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

t_img		*create_img(t_mlxwin *win)
{
	t_img	*ret;

	ret = ft_memalloc(sizeof(t_img));
	ret->img = mlx_new_image(win->mlx, win->width, win->height);
	ret->bpp = 4;
	ret->sl = 400;
	ret->end = 0;
	return (ret);
}

t_mlxwin	*create_win(int width, int height, char *name)
{
	t_mlxwin	*win;

	win = ft_memalloc(sizeof(t_mlxwin));
	win->height = height;
	win->width = width;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, width, height, name);
	win->img = create_img(win);
	return (win);
}

t_color		*create_color(int red, int green, int blue, int alpha)
{
	t_color	*color;

	color = ft_memalloc(sizeof(t_color));
	color->red = red;
	color->green = green;
	color->blue = blue;
	color->alpha = alpha;
	return (color);
}

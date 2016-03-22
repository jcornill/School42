/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:15:56 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/22 19:58:52 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		event_key_press(int keycode, void *param)
{
	param = 0;
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int		main(void)
{
	t_mlxwin	*window;
	t_line		*line;

	window = create_win(400, 400, "Fdf 42");
	for (int i = 0; i < 400; i++)
	{
	line = create_line(create_coord(0, i), create_coord(i, i),
	create_color(0, 0, 255, 0), create_color(255, 255, 0, 0));
	draw_line(window, line);
	line = create_line(create_coord(0, 400-i), create_coord(i, 400-i),
	create_color(255, 0, 0, 0), create_color(0, 255, 255, 0));
	draw_line(window, line);
	}
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
	mlx_key_hook(window->win, event_key_press, 0);
	mlx_loop(window->mlx);
}

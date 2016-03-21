/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:05:40 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/21 15:37:13 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(void)
{
	t_mlxwin	*window;
	t_line		*line;

	window = create_win(400, 400, "Fdf 42");
	line = create_line(create_coord(0, 10), create_coord(400, 10), 0x00FF0000, 0x000);
	draw_line(window, line);
	mlx_loop(window->mlx);
}

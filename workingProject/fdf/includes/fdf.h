/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:13:48 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/22 15:45:02 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
#  include <stdio.h>

typedef struct		s_img
{
	void			*img;
	int				bpp;
	int				sl;
	int				end;
}					t_img;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
	int				alpha;
}					t_color;

typedef struct		s_mlxwin
{
	void			*mlx;
	void			*win;
	t_img			*img;
	int				width;
	int				height;
}					t_mlxwin;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_line
{
	t_coord			*start;
	t_coord			*end;
	t_color			*color_start;
	t_color			*color_end;
}					t_line;

t_coord				*create_coord(int x, int y);
t_line				*create_line(t_coord *start, t_coord *end, t_color *cstart,
					t_color *cend);
t_mlxwin			*create_win(int width, int height, char *name);
void				draw_line(t_mlxwin *win, t_line *line);
t_color				*create_color(int red, int green, int blue, int alpha);

#endif

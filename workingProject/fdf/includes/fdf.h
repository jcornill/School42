/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:13:48 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/21 14:28:06 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_mlxwin
{
	void			*mlx;
	void			*win;
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
	int				color_start;
	int				color_end;
}					t_line;

t_coord				*create_coord(int x, int y);
t_line				*create_line(t_coord *start, t_coord *end, int cstart,
					int cend);
t_mlxwin			*create_win(int width, int height, char *name);
void				draw_line(t_mlxwin *win, t_line *line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 16:18:15 by jcornill          #+#    #+#             */
/*   Updated: 2016/04/01 18:27:20 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef struct		s_grid
{
	int				width;
	int				heigth;
	char			*grid;
}					t_grid;

typedef struct		s_piece
{
	int				width;
	int				heigth;
	char			*piece;
}					t_piece;

typedef struct		s_data
{
	int				player;
	t_grid			*grid;
	t_piece			*piece;
}					t_data;

t_data				*process_input(char *str, int player);
t_piece				*init_piece(char *str, t_data *data);
void				process(t_data *data);

#endif

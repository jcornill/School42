/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:32:44 by jcornill          #+#    #+#             */
/*   Updated: 2016/02/23 16:32:46 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
#  include <stdio.h>

typedef struct		s_link
{
	char			*room_a;
	char			*room_b;
}					t_link;

typedef struct		s_data
{
	int				nb_ants;
	t_list			*rooms_name;
	t_list			*links;
	char			*start_room;
	char			*end_room;
}					t_data;

t_data				*check_entry(char *str, t_list **entry);
void				err_exit(int id, char *err);
void				print_list(t_list *elem);
int					set_s_e_room(int nb_sp, int room, t_data *data, char *ret);
#endif

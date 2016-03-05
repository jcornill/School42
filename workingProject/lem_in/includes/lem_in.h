/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:32:07 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/05 16:37:20 by jcornill         ###   ########.fr       */
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

typedef struct		s_room_link
{
	char			*room;
	t_list			*linked;
}					t_room_link;

typedef struct		s_path
{
	t_list			*room_path;
	int				length;
}					t_path;

typedef struct		s_data
{
	int				nb_ants;
	t_list			*rooms_name;
	t_list			*links;
	char			*start_room;
	char			*end_room;
	t_list			*room_links;
	t_list			*tested_room;
	t_path			*best_path;
	int				best_length;
	int				act_length;
}					t_data;

t_data				*check_entry(char *str, t_list **entry);
void				err_exit(int id, char *err);
void				print_list(t_list *elem);
int					set_s_e_room(int nb_sp, int room, t_data *data, char *ret);
void				link_checker(t_data *data);
void				path_process(t_data *data);
int					process_room(char *room, t_data *data, int length);

#endif

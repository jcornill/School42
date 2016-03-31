/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:32:07 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/31 15:35:51 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"

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

typedef struct		s_room
{
	char			*room;
	int				dist_to_end;
	int				ants_in_room;
}					t_room;

typedef struct		s_ant
{
	int				id;
	char			*actual_room;
	char			*next_room;
}					t_ant;

typedef struct		s_data
{
	int				nb_ants;
	int				end_ants;
	t_list			*rooms_name;
	t_list			*links;
	char			*start_room;
	char			*end_room;
	t_list			*room_links;
	t_list			*best_path;
	t_list			*lst_room;
	t_list			*lst_ants;
	int				s;
	int				e;
}					t_data;

t_data				*check_entry(char *str, t_list **entry, char *room);
void				err_exit(int id, char *err);
void				print_list(t_list *elem);
int					set_s_e_room(int room, t_data *data, char *ret);
void				link_checker(t_data *data);
void				path_process(t_data *data);
int					process_room(char *room, t_data *data);
void				ants_mover(t_data *data);
void				set_ant(t_data *data);
char				*get_next_room(char *room, t_data *data);
void				set_room_link(t_data *data);
int					move_ant(t_data *data, t_ant *ant);
void				reset_room(char *room, t_data *data);
void				print_move(int ants_id, char *room);
void				get_best_path(char *room, t_data *data);
void				process_room_v3(char *room, t_data *data, int length);
int					check_room_2(char *room, t_data *data);
void				check_nb_ants(t_data *data, char *str, t_list **entry);
int					c_nbants(char *str);
t_data				*init_data(char *str, t_list **entry);
int					test(char *str, t_data *data);

#endif

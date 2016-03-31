/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:31:49 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/31 15:36:49 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		test(char *str, t_data *data)
{
	if (ft_strcmp(str, "##start") == 0 && data->s != 0)
		return (1);
	if (ft_strcmp(str, "##start") == 0)
		data->s = 1;
	if (ft_strcmp(str, "##end") == 0 && data->e != 0)
		return (1);
	if (ft_strcmp(str, "##end") == 0)
		data->e = 1;
	return (0);
}

int		check_room_2(char *room, t_data *data)
{
	t_list		*rooms;

	rooms = data->rooms_name;
	while (rooms != NULL)
	{
		if (ft_strcmp(rooms->content, room) == 0)
			return (0);
		rooms = rooms->next;
	}
	return (1);
}

int		set_s_e_room(int room, t_data *data, char *ret)
{
	if (room == 10)
		data->start_room = ret;
	else if (room == -5)
		data->end_room = ret;
	else if (room == 5 && (data->start_room = ret) == ret)
		data->end_room = ret;
	return (0);
}

void	check_nb_ants(t_data *data, char *str, t_list **entry)
{
	while (get_next_line(0, &str) > 0)
	{
		if (c_nbants(str) == 0)
		{
			ft_lstpush(&(*entry), ft_lstnew(str, ft_strlen(str)));
			if (c_nbants(str) == -1)
				err_exit(1, "Need ant number !");
			continue ;
		}
		else
		{
			if (data->nb_ants == -1 && (data->nb_ants = c_nbants(str)) <= 0)
				err_exit(1, "Need ant number !");
			ft_lstpush(&(*entry), ft_lstnew(str, ft_strlen(str)));
			break ;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:31:49 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/29 10:25:26 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_room_2(char *room, t_data *data)
{
	t_list		*rooms;

	rooms = data->rooms_name;
	while (rooms != NULL)
	{
		if (ft_strcmp(rooms->content, room) == 0)
			return(0);
		rooms = rooms->next;
	}
	return (1);
}

int		set_s_e_room(int room, t_data *data, char *ret)
{
	if ((room == 10 || room == 5) && data->start_room != 0)
		err_exit(10, "Two start room define !");
	if ((room == -5 || room == 5) && data->end_room != 0)
		err_exit(11, "Two end room define !");
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

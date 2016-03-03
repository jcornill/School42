/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 19:47:01 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/03 19:13:00 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*get_linked_room(char *room, t_data *data)
{
	t_list		*room_link;
	t_room_link	*roomlink;

	room_link = (t_list *)data->room_links;
	while (room_link != NULL)
	{
		roomlink = (t_room_link *)room_link->content;
		if (ft_strcmp(roomlink->room, room) == 0)
			return (roomlink->linked);
		room_link = room_link->next;
	}
	return (NULL);
}

int		is_room_tested(char *room, t_data *data)
{
	t_list		*rooms;

	rooms = data->tested_room;
	while (rooms != NULL)
	{
		if (ft_strcmp(rooms->content, room) == 0)
			return (1);
		rooms = rooms->next;
	}
	return (0);
}

int		process_room(char *room, t_data *data)
{
	t_list		*rooms;
	int			length;

	if (ft_strcmp(room, data->start_room) == 0)
	{
		length = 1;
		ft_lstpush(&data->best_path->room_path,
		ft_lstnew(room, ft_strlen(room)));
		return (length);
	}
	rooms = get_linked_room(room, data);
	while (rooms != NULL)
	{
		printf("%s->%s\n", room, rooms->content);
		if (is_room_tested(rooms->content, data))
		{
			rooms = rooms->next;
			continue ;
		}
	//	printf("%s\n", room);
		ft_lstpush(&data->tested_room,
		ft_lstnew(rooms->content, ft_strlen(rooms->content)));
		if ((length = process_room(rooms->content, data)) >= 0)
		{
			length++;
			ft_lstpush(&data->best_path->room_path,
			ft_lstnew(room, ft_strlen(room)));
			return (length);
		}
		rooms = rooms->next;
	}
	return (-1);
}

void	path_process(t_data *data)
{
	data->best_path = (t_path *)ft_memalloc(sizeof(t_path));
	ft_lstpush(&data->tested_room,
	ft_lstnew(data->end_room, ft_strlen(data->end_room)));
	data->best_path->length = process_room(data->end_room, data);
}

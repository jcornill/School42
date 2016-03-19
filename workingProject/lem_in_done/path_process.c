/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 19:47:01 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/19 16:02:58 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list		*get_linked_room(char *room, t_data *data)
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

int			is_room_tested(char *room, t_data *data, int length)
{
	t_list		*rooms;
	t_room		*test_room;

	rooms = data->lst_room;
	while (rooms != NULL)
	{
		test_room = (t_room *)rooms->content;
		if (ft_strcmp(test_room->room, room) == 0)
		{
			if (test_room->dist_to_end > length)
				test_room->dist_to_end = length + 1;
			return (1);
		}
		rooms = rooms->next;
	}
	return (0);
}

void		process_room_v3(char *room, t_data *data, int length)
{
	t_list		*rooms;
	t_room		*new_room;

	rooms = get_linked_room(room, data);
	new_room = ft_memalloc(sizeof(t_room));
	new_room->room = room;
	new_room->dist_to_end = length;
	new_room->ants_in_room = 0;
	ft_lstpush(&data->lst_room, ft_lstnew(new_room, sizeof(t_room)));
	if (ft_strcmp(room, data->start_room) == 0)
		return ;
	while (rooms != NULL)
	{
		if (is_room_tested(rooms->content, data, length))
		{
			rooms = rooms->next;
			continue ;
		}
		process_room_v3(rooms->content, data, length + 1);
		rooms = rooms->next;
	}
}

int			get_dist_from_room(char *room, t_data *data)
{
	t_list		*rooms;
	t_room		*test_room;

	rooms = data->lst_room;
	while (rooms != NULL)
	{
		test_room = (t_room *)rooms->content;
		if (ft_strcmp(test_room->room, room) == 0)
			return (test_room->dist_to_end);
		rooms = rooms->next;
	}
	return (-1);
}

void		get_best_path(char *room, t_data *data)
{
	t_list	*linked;
	int		act;
	int		best;
	char	*best_room;

	best = 99999;
	linked = get_linked_room(room, data);
	if (linked == NULL)
		best_room = room;
	while (linked != NULL)
	{
		if ((act = get_dist_from_room(linked->content, data)) < best)
		{
			best = act;
			best_room = linked->content;
		}
		linked = linked->next;
	}
	ft_lstpush(&data->best_path,
	ft_lstnew(best_room, ft_strlen(best_room)));
	if (ft_strcmp(best_room, data->end_room) != 0)
		get_best_path(best_room, data);
}

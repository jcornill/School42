/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 19:47:01 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/17 16:08:06 by jcornill         ###   ########.fr       */
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

int		is_room_tested(char *room, t_data *data, int length)
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

int		get_dist_from_room(char *room, t_data *data)
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

void	get_best_path(char *room, t_data *data)
{
	t_list	*linked;
	int		act;
	int		best;
	char	*best_room;

	best = 99999;
	linked = get_linked_room(room, data);
	printf("%s\n", "test");
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

void	path_process(t_data *data)
{
	process_room_v3(data->end_room, data, 0);
	ft_lstpush(&data->best_path,
	ft_lstnew(data->start_room, ft_strlen(data->start_room)));
	get_best_path(data->start_room, data);
}

// void	path_process(t_data *data)
// {
//  	int		i;
// 	int		cpt;
//
// 	i = 1;
// 	cpt = 0;
// 	while (i > 0 && cpt < 10)
// 	{
// 		data->roomlinkpath = (char *)ft_memalloc(1);
// 		data->act_length = 0;
// 		add_tested_room(data->start_room, data, data->start_room);
// 		adding_str(data->roomlinkpath, data->start_room, data);
// 		i = process_room_v2(data->start_room, data, data->start_room);
// 		printf("Final : '%s'\n", data->roomlinkpath);
// 		ft_lstpush(&data->lst_roomlinkpath,
// 		ft_lstnew(data->roomlinkpath, ft_strlen(data->roomlinkpath)));
// 		ft_lstdel(&data->tested_room, delete);
// 		//free(data->roomlinkpath);
// 		cpt++;
// 	}
// }

// void	path_process(t_data *data)
// {
// 	int		i;
// 	char	*cpy;
// 	int		cpt;
//
// 	data->best_path = (t_path *)ft_memalloc(sizeof(t_path));
// 	data->best_path->length = 9999;
// 	i = 0;
// 	cpt = 0;
// 	while (i != -1 && cpt < 5)
// 	{
// 		data->roomlinkpath = (char *)ft_memalloc(1);
// 		data->act_length = 0;
// 		ft_lstpush(&data->tested_room,
// 		ft_lstnew(data->end_room, ft_strlen(data->end_room)));
// 		i = process_room(data->end_room, data);
// 		// temp = ft_strjoin(" ", ft_itoa(data->act_length));
// 		// printf("Add : '%s'\n", temp);
// 		// temp2 = data->roomlinkpath;
// 		// data->roomlinkpath = ft_strjoin(data->roomlinkpath, temp);
// 		// free(temp2);
// 		// free(temp);
// 		ft_putstr(data->roomlinkpath);
// 		cpy = ft_strdup(data->roomlinkpath);
// 		ft_lstpush(&data->lst_roomlinkpath,
// 		ft_lstnew(cpy, ft_strlen(cpy)));
// 		lstfree(&data->tested_room, data);
// 		free(data->roomlinkpath);
// 		printf("\n0.5\n");
// 		cpt++;
// 	}
// }

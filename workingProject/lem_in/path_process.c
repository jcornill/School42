/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 19:47:01 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/16 16:41:52 by jcornill         ###   ########.fr       */
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

int		is_room_tested(char *room, t_data *data, char *prev_room)
{
	t_list		*rooms;

	rooms = data->tested_room;
	while (rooms != NULL)
	{
		if (ft_strcmp(rooms->content, room) == 45)
		{
			if (ft_strstr(rooms->content, prev_room) != 0)
				return (1);
		}
		rooms = rooms->next;
	}
	return ((int)prev_room * 0);
}

char	*adding_str(char *src, char *str, t_data *data)
{
	char	*temp;

	printf("Add : '%s'\n", str);
	temp = src;
	src = ft_strjoin(src, str);
	free(temp);
	temp = src;
	src = ft_strjoin(src, "-");
	free(temp);
	data->act_length++;
	return (src);
}

void	rem_str(t_data *data, char *room)
{
	printf("Rem : '%s'\n", room);
	data->roomlinkpath[ft_strlen(data->roomlinkpath) - 2] = 0;
	data->act_length--;
}


int		is_path_tested(t_data *data)
{
	t_list		*rooms;

	adding_str(data->roomlinkpath, ft_itoa(data->act_length), data);
	rooms = data->lst_roomlinkpath;
	while (rooms != NULL)
	{
		printf("Cmp : %s : %s\n", data->roomlinkpath, rooms->content);
		if (ft_strcmp(rooms->content, data->roomlinkpath) == 0)
		{
			rem_str(data, "length");
			return (1);
		}
		rooms = rooms->next;
	}
	return (0);
}

void	add_tested_room(char *room, t_data *data, char *prev_room)
{
	char	*tested_room;
	char	*temp;

	tested_room = ft_strdup(prev_room);
	temp = tested_room;
	tested_room = ft_strjoin(tested_room, "->");
	free(temp);
	temp = tested_room;
	tested_room = ft_strjoin(tested_room, room);
	free(temp);
	printf("Adding : %s to tested room\n", tested_room);
	ft_lstpush(&data->tested_room,
	ft_lstnew(tested_room, ft_strlen(tested_room)));
}

int			process_room_v3(char *room, t_data *data)
{
	t_list		*rooms;
	int			best;
	int			act;

	if (ft_strcmp(room, data->end_room) == 0)
		return (1);
	rooms = get_linked_room(room, data);
	best = 0;
	while (rooms != NULL)
	{
		if (is_room_tested(rooms->content, data, room))
		{
			rooms = rooms->next;
			continue ;
		}
		if ((act = process_room_v3(rooms->content, data)) > best)
		{
			best = act;
		}
	}
	return (best + 1);
}

// int		process_room_v2(char *room, t_data *data, char *prev_room)
// {
// 	t_list		*rooms;
//
// 	printf("Prev Room : '%s'\n", prev_room);
// 	if (ft_strcmp(room, data->end_room) == 0 && !is_path_tested(data))
// 		return (1);
// 	rooms = get_linked_room(room, data);
// 	while (rooms != NULL)
// 	{
// 		if (is_room_tested(rooms->content, data, room))
// 		{
// 			rooms = rooms->next;
// 			continue ;
// 		}
// 		add_tested_room(rooms->content, data, room);
// 		adding_str(data->roomlinkpath, rooms->content, data);
// 		if (process_room_v2(rooms->content, data, room))
// 			return (1);
// 		else
// 			rem_str(data, rooms->content);
// 	}
// 	return (0);
// }

// int		process_room(char *room, t_data *data)
// {
// 	t_list		*rooms;
// 	char		*temp;
//
// 	printf("Add : '%s'\n", room);
// 	temp = data->roomlinkpath;
// 	data->roomlinkpath = ft_strjoin(data->roomlinkpath, room);
// 	free(temp);
// 	temp = data->roomlinkpath;
// 	data->roomlinkpath = ft_strjoin(data->roomlinkpath, "-");
// 	free(temp);
// 	if (ft_strcmp(room, data->start_room) == 0 && !is_path_tested(data->roomlinkpath, data))
// 	{
// 		// ft_lstpush(&data->best_path->room_path,
// 		// ft_lstnew(room, ft_strlen(room)));
// 		data->act_length++;
// 		return (1);
// 	}
// 	else if (ft_strcmp(room, data->start_room) == 0)
// 	{
// 		printf("Rem : '%s'\n", data->start_room);
// 		data->roomlinkpath[ft_strlen(data->roomlinkpath) - 2] = 0;
// 	}
// 	rooms = get_linked_room(room, data);
// 	while (rooms != NULL)
// 	{
// 		// printf("%s->%s\n", room, rooms->content);
// 		if (is_room_tested(rooms->content, data))
// 		{
// 			rooms = rooms->next;
// 			continue ;
// 		}
// 		ft_lstpush(&data->tested_room,
// 		ft_lstnew(rooms->content, ft_strlen(rooms->content)));
// 		if ((process_room(rooms->content, data)) >= 0)
// 		{
// 			// temp = data->roomlinkpath;
// 			// data->roomlinkpath = ft_strjoin(data->roomlinkpath, "-");
// 			// free(temp);
// 			// printf("Add : '%s'\n", room);
// 			// temp = data->roomlinkpath;
// 			// data->roomlinkpath = ft_strjoin(data->roomlinkpath, room);
// 			// free(temp);
// 			// ft_lstpush(&data->best_path->room_path,
// 			// ft_lstnew(room, ft_strlen(room)));
// 			data->act_length++;
// 			return (1);
// 		}
// 		printf("Rem : '%s'\n", rooms->content);
// 		data->roomlinkpath[ft_strlen(data->roomlinkpath) - 2] = 0;
// 		printf("Rem : '%s'\n", room);
// 		data->roomlinkpath[ft_strlen(data->roomlinkpath) - 2] = 0;
// 		rooms = rooms->next;
// 	}
// 	return (-1);
// }

// void	lstfree(t_list **alst, t_data *data)
// {
// 	t_list	*src;
//
// 	src = *alst;
// 	if (src->next != NULL)
// 		lstfree(&src->next, data);
// 	free(src);
// 	*alst = NULL;
// }
//
// void	delete(void *cont, size_t size)
// {
// 	size = 0;
// 	ft_memdel(&cont);
// }

void	path_process(t_data *data)
{
	int		i;
	int		cpt;

	i = 1;
	cpt = 0;
	while (i > 0 && cpt < 10)
	{

	}
}

// void	path_process(t_data *data)
// {
// 	int		i;
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

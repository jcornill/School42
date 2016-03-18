/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:31:17 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/18 14:21:56 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	cmp_link(char *r_a, char *r_b, t_list *links)
{
	t_link	*link;
	int		room;

	room = 0;
	link = (t_link *)links->content;
	if (ft_strcmp(r_a, link->room_a) == 0 && ft_strcmp(r_b, link->room_b) == 0)
		room++;
	while (links->next != NULL)
	{
		links = links->next;
		link = (t_link *)links->content;
		if (ft_strcmp(r_a, link->room_a) == 0 &&
			ft_strcmp(r_b, link->room_b) == 0)
			room++;
	}
	if (room > 1)
		err_exit(12, "Two identicals links !");
}

t_room_link	*iter_link(t_list *links, char *room)
{
	t_link		*link;
	t_room_link	*ret;

	ret = ft_memalloc(sizeof(t_room_link));
	link = (t_link *)links->content;
	if (ft_strcmp(link->room_a, room) == 0)
		ft_lstpush(&ret->linked, ft_lstnew(link->room_b, ft_strlen(room)));
	else if (ft_strcmp(link->room_b, room) == 0)
		ft_lstpush(&ret->linked, ft_lstnew(link->room_a, ft_strlen(room)));
	while (links->next != NULL)
	{
		links = links->next;
		link = (t_link *)links->content;
		if (ft_strcmp(link->room_a, room) == 0)
			ft_lstpush(&ret->linked, ft_lstnew(link->room_b, ft_strlen(room)));
		else if (ft_strcmp(link->room_b, room) == 0)
			ft_lstpush(&ret->linked, ft_lstnew(link->room_a, ft_strlen(room)));
	}
	ret->room = room;
	return (ret);
}

void		set_room_link(t_data *data)
{
	t_list		*rooms;
	char		*name;
	t_room_link	*ret;

	rooms = data->rooms_name;
	data->room_links = 0;
	while (rooms != NULL)
	{
		name = (char *)rooms->content;
		ret = iter_link(data->links, name);
		ft_lstpush(&data->room_links, ft_lstnew(ret, sizeof(t_room_link)));
		rooms = rooms->next;
	}
}

void		link_checker(t_data *data)
{
	t_list	*links;
	t_link	*link;

	links = data->links;
	if (links == 0)
		return ;
	link = (t_link *)links->content;
	cmp_link(link->room_a, link->room_b, data->links);
	while (links->next != NULL)
	{
		links = links->next;
		link = (t_link *)links->content;
		cmp_link(link->room_a, link->room_b, data->links);
	}
	set_room_link(data);
}

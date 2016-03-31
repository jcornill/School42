/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:31:17 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/31 14:00:39 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		if (data->links == NULL)
			return ;
		ret = iter_link(data->links, name);
		ft_lstpush(&data->room_links, ft_lstnew(ret, sizeof(t_room_link)));
		rooms = rooms->next;
	}
}

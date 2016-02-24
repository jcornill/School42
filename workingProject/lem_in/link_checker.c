/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:31:17 by jcornill          #+#    #+#             */
/*   Updated: 2016/02/24 19:34:25 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	cmp_link(char *room_a, char *room_b, t_list *links)
{
	t_link	*link;
	int		room;

	room = 0;
	link = (t_link *)links->content;
	if (room_a == link->room_a && room_b == link->room_b)
		room++;
	while (links->next != NULL)
	{
		link = (t_link *)links->content;
		links->next = links;
		if (room_a == link->room_a && room_b == link->room_b)
			room++;
	}
	if (room > 1)
		err_exit(12, "Two identicals links !");
}

void		link_checker(t_data *data)
{
	t_list	*links;
	t_link	*link;

	printf("%d\n", __LINE__);
	links = data->links;
	link = (t_link *)links->content;
	printf("%d\n", __LINE__);
	cmp_link(link->room_a, link->room_b, data->links);
	printf("%d\n", __LINE__);
	while (links->next != NULL)
	{
		link = (t_link *)links->content;
		links->next = links;
		cmp_link(link->room_a, link->room_b, data->links);
	}
}

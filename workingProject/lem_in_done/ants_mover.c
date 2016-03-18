/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_mover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:00:12 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/18 14:21:12 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_move(int ants_id, char *room)
{
	ft_putchar('L');
	ft_putnbr(ants_id);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

char	*get_next_room(char *room, t_data *data)
{
	t_list		*rooms;

	rooms = data->best_path;
	while (rooms != NULL)
	{
		if (ft_strcmp(rooms->content, room) == 0)
		{
			if (rooms->next != NULL)
				return (rooms->next->content);
		}
		rooms = rooms->next;
	}
	return (room);
}

void	reset_room(char *room, t_data *data)
{
	t_list		*rooms;
	t_room		*act_room;

	rooms = data->lst_room;
	while (rooms != NULL)
	{
		act_room = rooms->content;
		if (ft_strcmp(room, act_room->room) == 0)
		{
			act_room->ants_in_room = 0;
			return ;
		}
		rooms = rooms->next;
	}
}

int		check_empty_room(char *room, t_data *data)
{
	t_list		*rooms;
	t_room		*act_room;

	rooms = data->lst_room;
	while (rooms != NULL)
	{
		act_room = rooms->content;
		if (ft_strcmp(room, act_room->room) == 0 && act_room->ants_in_room == 0)
		{
			if (ft_strcmp(act_room->room, data->end_room) != 0)
				act_room->ants_in_room = 1;
			return (1);
		}
		rooms = rooms->next;
	}
	return (0);
}

void	ants_mover(t_data *data)
{
	t_list		*ants;
	t_ant		*ant;
	int			i;

	set_ant(data);
	i = data->nb_ants;
	while (i > 0)
	{
		ants = data->lst_ants;
		while (ants != NULL)
		{
			ant = ants->content;
			if (ft_strcmp(ant->actual_room, data->end_room) == 0)
			{
				ants = ants->next;
				continue ;
			}
			if (check_empty_room(ant->next_room, data))
				if (move_ant(data, ant) &&
				ft_strcmp(ant->actual_room, data->end_room) == 0)
					i--;
			ants = ants->next;
		}
		ft_putchar('\n');
	}
}

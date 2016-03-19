/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:14:31 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/19 15:23:51 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_ant(t_data *data)
{
	int		i;
	t_ant	*new_ant;

	i = 0;
	while (i < data->nb_ants)
	{
		new_ant = ft_memalloc(sizeof(t_ant));
		new_ant->actual_room = data->start_room;
		new_ant->id = i + 1;
		new_ant->next_room = get_next_room(new_ant->actual_room, data);
		ft_lstpush(&data->lst_ants,
		ft_lstnew(new_ant, sizeof(t_ant)));
		i++;
	}
}

int		move_ant(t_data *data, t_ant *ant)
{
	reset_room(ant->actual_room, data);
	print_move(ant->id, ant->next_room);
	ant->actual_room = ant->next_room;
	ant->next_room = get_next_room(ant->actual_room, data);
	return (1);
}

void	path_process(t_data *data)
{
	process_room_v3(data->end_room, data, 0);
	ft_lstpush(&data->best_path,
	ft_lstnew(data->start_room, ft_strlen(data->start_room)));
	get_best_path(data->start_room, data);
}

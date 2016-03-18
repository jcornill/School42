/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:31:49 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/18 14:21:37 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	set_s_e_room(int nb_sp, int room, t_data *data, char *ret)
{
	if (nb_sp > 2)
		err_exit(4, "Unknown line ! (Space in room name ?)");
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

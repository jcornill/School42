/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_mover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:00:12 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/17 16:46:29 by jcornill         ###   ########.fr       */
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

void	ants_mover(t_data *data)
{
	int		i;

	i = 0;
	while (data->end_ants < data->nb_ants)
	{
		
		i++;
	}
}

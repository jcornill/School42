/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:00:03 by jcornill          #+#    #+#             */
/*   Updated: 2016/02/22 16:00:04 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(int *pile, int num, char c)
{
	int		i;
	int		temp;

	i = 0;
	temp = *(pile + i);
	while (i < *(pile + num) - 1)
	{
		*(pile + i) = *(pile + i + 1);
		i++;
	}
	*(pile + i) = temp;
	if (c == 'a' || c == 'b')
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, " ", 1);
	}
}

void	rrotates(int *pile_a, int *pile_b, int num)
{
	rrotate(pile_a, num, 0);
	rrotate(pile_b, num, 0);
	write(1, "rrr ", 4);
}

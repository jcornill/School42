/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:00:03 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/14 16:54:58 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *pile, int num, char c, int opt)
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
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, " ", 1);
	}
	if (opt == 1)
		debug_print(0, 0, num);
}

void	rotates(int *pile_a, int *pile_b, int num)
{
	rrotate(pile_a, num, 0, 0);
	rrotate(pile_b, num, 0, 0);
	write(1, "rr ", 3);
}

void	move_left_pile(int *pile, int num)
{
	int		i;

	i = 0;
	while (i < *(pile + num) - 1)
	{
		*(pile + i) = *(pile + i + 1);
		i++;
	}
	*(pile + i) = 0;
}

void	move_right_pile(int *pile, int num)
{
	int		i;

	i = *(pile + num);
	while (i > 0)
	{
		*(pile + i) = *(pile + i - 1);
		i--;
	}
	*(pile + i) = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:44:22 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/14 16:54:59 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *pile, int num, char c, int opt)
{
	int		num_pile;
	int		temp;

	num_pile = *(pile + num);
	if (num_pile > 1)
	{
		temp = *(pile);
		*(pile) = *(pile + 1);
		*(pile + 1) = temp;
		if (c == 'a' || c == 'b')
		{
			write(1, "s", 1);
			write(1, &c, 1);
			write(1, " ", 1);
		}
	}
	if (opt == 1)
		debug_print(0, 0, num);
}

void	swaps(int *pile_a, int *pile_b, int num)
{
	swap(pile_a, num, 0, 0);
	swap(pile_b, num, 0, 0);
	write(1, "ss ", 3);
}

void	push(int *pile1, int *pile2, int num, char c)
{
	int		opt;

	opt = (c == 107 || c == 108);
	while (c > 100)
		c -= 10;
	if (*(pile1 + num) > 0)
	{
		move_right_pile(pile2, num);
		*(pile2) = *(pile1);
		*(pile1) = 0;
		move_left_pile(pile1, num);
		*(pile1 + num) = *(pile1 + num) - 1;
		*(pile2 + num) = *(pile2 + num) + 1;
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, " ", 1);
	}
	if (opt)
		debug_print(0, 0, num);
}

void	rrotate(int *pile, int num, char c, int opt)
{
	int		i;
	int		temp;

	i = *(pile + num) - 1;
	temp = *(pile + i);
	while (i > 0)
	{
		*(pile + i) = *(pile + i - 1);
		i--;
	}
	*(pile + i) = temp;
	if (c == 'a' || c == 'b')
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, " ", 1);
	}
	if (opt == 1)
		debug_print(0, 0, num);
}

void	rrotates(int *pile_a, int *pile_b, int num, int opt)
{
	rotate(pile_a, num, 0, opt);
	rotate(pile_b, num, 0, opt);
	write(1, "rrr ", 4);
}

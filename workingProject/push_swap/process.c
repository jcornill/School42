/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:22:31 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/07 18:25:43 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_pile_rorder(int *pile, int num)
{
	int	i;

	i = 0;
	while (i < *(pile + num) - 1)
	{
		if (*(pile + i + 1) > *(pile + i))
			return (0);
		i++;
	}
	return (1);
}

static int	check_pile_order(int *pile, int num)
{
	int	i;

	i = 0;
	while (i < *(pile + num) - 1)
	{
		if ((*(pile + i)) > (*(pile + i + 1)))
			return (0);
		i++;
	}
	return (1);
}

static int	check_max(int *pile, int num, int max)
{
	int	i;

	i = 0;
	while (i < *(pile + num) - 1)
	{
		if ((*(pile + i)) > max)
			return (0);
		i++;
	}
	return (1);
}

void		process(int *pile_a, int *pile_b, int num, int opt)
{
	int	i;

	i = 1;
	if (check_pile_order(pile_a, num) && *(pile_b + num) == 0)
		return ;
	while (!check_pile_order(pile_a, num) || *(pile_b + num) != 0)
	{
		if (*(pile_a) < *(pile_a + *(pile_a + num) - 1) && *(pile_a)
			< *(pile_a + *(pile_a + num) - 2))
			rrotate(pile_a, num, 'a', opt);
		if (*(pile_a + num - i) > *(pile_a + num - i - 1))
			swap(pile_a, num, 'a', opt);
		while (!check_max(pile_a, num, *(pile_a + (*(pile_a + num)) - 1)))
			rrotate(pile_a, num, 'a', opt);
		if (!check_pile_order(pile_a, num))
			push(pile_a, pile_b, num, 'b' + (opt * 10));
		if (check_pile_rorder(pile_b, num) && check_pile_order(pile_a, num))
		{
			while (*(pile_b + num) != 0)
				push(pile_b, pile_a, num, 'a' + (opt * 10));
			return ;
		}
		i++;
	}
}

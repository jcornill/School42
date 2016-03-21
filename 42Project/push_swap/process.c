/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:22:31 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/16 13:04:21 by jcornill         ###   ########.fr       */
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

static int	check_min(int *pile, int num, int min)
{
	int	i;

	i = 0;
	while (i < *(pile + num))
	{
		if ((*(pile + i)) < min)
			return (0);
		i++;
	}
	return (1);
}

int			opti(int *pile, int num, int opt)
{
	int	i;

	i = 0;
	while (i < *(pile + num) - 2)
	{
		if ((*(pile + i)) > (*(pile + i + 1)))
			return (0);
		i++;
	}
	if (*(pile + num - 1) < *(pile + num - 2))
	{
		rrotate(pile, num, 'a', opt);
		rrotate(pile, num, 'a', opt);
		swap(pile, num, 'a', opt);
		rotate(pile, num, 'a', opt);
		rotate(pile, num, 'a', opt);
	}
	else
	{
		return (0);
	}
	return (1);
}

void		process(int *pile_a, int *pile_b, int num, int opt)
{
	if (num <= 1 || check_pile_order(pile_a, num) || opti(pile_a, num, opt))
		return ;
	while (check_pile_order(pile_a, num) != 1 || *(pile_b + num) > 0)
	{
		if (*(pile_a) > *(pile_a + 1) && check_min(pile_a, num, *(pile_a + 1)))
			swap(pile_a, num, 'a', opt);
		if (check_min(pile_a, num, *(pile_a)) && !check_pile_order(pile_a, num))
			push(pile_a, pile_b, num, 'b' + (opt * 10));
		else if (!check_pile_order(pile_a, num))
		{
			if (where_min(pile_a, num) == 0)
				rotate(pile_a, num, 'a', opt);
			else
				rrotate(pile_a, num, 'a', opt);
		}
		while (check_pile_order(pile_a, num) && *(pile_b + num) > 0)
			push(pile_b, pile_a, num, 'a' + (opt * 10));
	}
	return ;
	check_pile_rorder(pile_b, 0);
}

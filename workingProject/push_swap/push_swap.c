/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:15:49 by jcornill          #+#    #+#             */
/*   Updated: 2016/02/21 16:38:30 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_list *elem)
{
	ft_putnbr(ft_atoi(elem->content));
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	t_list *pile_a;

	if (argc != 1)
	{
		pile_a = get_pile_a(argv, argc);
		ft_lstiter(pile_a, &print);
	}
	return (0);
}

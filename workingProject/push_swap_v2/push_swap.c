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

void		debug_print(int *pile, int num)
{
	int		i;

	i = 1;
	while (i <= *(pile + num))
	{
		ft_putnbr(*(pile + (i - 1)));
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int			main(const int argc, char **argv)
{
	int		*pile_a;
	int		*pile_b;
	int		debug;

	debug = 0;
	if (argv[1] == "-v")
		debug = 1;
	if (argc != 1)
	{
		if ((pile_a = get_pile_a(argv, argc)) == NULL)
			return (write(2, "Error\n", 6) * 0 + 1);
		if ((pile_b = get_pile_b(argc)) == NULL)
			return (write(2, "Error\n", 6) * 0 + 1);
		process(pile_a, pile_b, argc - 1);
		ft_putchar('\n');
		debug_print(pile_a, argc - 1);
		free(pile_a);
		free(pile_b);
	}
	return (0);
}

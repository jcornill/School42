/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:15:49 by jcornill          #+#    #+#             */
/*   Updated: 2016/03/11 20:42:48 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		debug_print(int *pile1, int *pile2, int num)
{
	int			i;
	static int	*pile_a = 0;
	static int	*pile_b = 0;

	if (pile_a == 0 && pile_b == 0)
	{
		pile_a = pile1;
		pile_b = pile2;
		return ;
	}
	i = 1;
	ft_putstr("\na:");
	while (i <= *(pile_a + num))
	{
		ft_putnbr(*(pile_a + (i - 1)));
		ft_putchar(i++ * 0 + 32);
	}
	i = 1;
	ft_putstr("\nb:");
	while (i <= *(pile_b + num))
	{
		ft_putnbr(*(pile_b + (i - 1)));
		ft_putchar(i++ * 0 + 32);
	}
	ft_putchar('\n');
}

int			main(const int argc, char **argv)
{
	int		*pile_a;
	int		*pile_b;
	int		opt;

	if (argc == 1 && (opt = 0) == 0)
		return (0);
	if (ft_strcmp(argv[1], "-v") == 0)
		opt = 1;
	else if (ft_strcmp(argv[1], "-a") == 0)
		opt = 2;
	if (argc != 1)
	{
		if ((pile_a = get_pile_a(argv, argc - (opt > 0), opt)) == NULL)
			return (write(2, "Error\n", 6) * 0 + 1);
		if ((pile_b = get_pile_b(argc - (opt > 0))) == NULL)
			return (write(2, "Error\n", 6) * 0 + 1);
		debug_print(pile_a, pile_b, argc - 1 - (opt > 0));
		process(pile_a, pile_b, argc - 1 - (opt > 0), (opt == 1));
		ft_putchar('\n');
		if (opt == 2)
			debug_print(0, 0, argc - 1 - (opt > 0));
		free(pile_a);
		free(pile_b);
	}
	return (0);
}

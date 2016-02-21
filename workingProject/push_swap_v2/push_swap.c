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

int		main(const int argc, char **argv)
{
	int		*pile_a;
	int		pile_b[argc];
	int		i;

	i = 1;
	if (argc != 1)
	{
		while (i < argc)
		{
			if ((pile_a = get_pile_a(argv, argc)) == NULL)
				return (write(2, "Error\n", 6) * 0 + 1);
			printf("%d:", *(pile_a + (i - 1) * sizeof(int)));
			i++;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:46:20 by jcornill          #+#    #+#             */
/*   Updated: 2016/02/21 16:46:22 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_double(int *pile, int num, int nb)
{
	int		i;

	i = 0;
	while ( i < nb)
	{
		if (*(pile + i * sizeof(int)) == num)
		{
			ft_putnbr(num);
			return (0);
		}
		i++;
	}
	return (1);
}

static int		check_error(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int				*get_pile_a(char **str, int nb_num)
{
	int		i;
	int		*ret;

	i = 1;
	ret = ft_memalloc(sizeof(int) * nb_num);
	while (i < nb_num)
	{
		if (check_error(str[i]) && check_double(ret, ft_atoi(str[i]), i))
			*(ret + (i - 1) * sizeof(int)) = ft_atoi(str[i]);
		else
			return (NULL);
		i++;
	}
	return (ret);
}

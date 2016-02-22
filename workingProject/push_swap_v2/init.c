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
	int			i;
	static int	bool = 0;

	i = 0;
	while (i < nb)
	{
		if (bool > 0 && num == 0)
			return (0);
		if (*(pile + i) == num && num != 0)
			return (0);
		i++;
		if (num == 0)
			bool++;
	}
	return (1);
}

static int		check_error(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
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
	if (!(ret = ft_memalloc(4 * nb_num)))
		return (NULL);
	while (i < nb_num)
	{
		if (check_error(str[i]) && check_double(ret, ft_atoi(str[i]), i))
			*(ret + (i - 1)) = ft_atoi(str[i]);
		else
			return (NULL);
		i++;
	}
	*(ret + (i - 1)) = nb_num - 1;
	return (ret);
}

int				*get_pile_b(int nb_num)
{
	int		*ret;

	if (!(ret = ft_memalloc(4 * nb_num)))
		return (NULL);
	*(ret + (nb_num - 1)) = 0;
	return (ret);
}

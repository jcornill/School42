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

t_list			*get_pile_a(char **str, int nb_num)
{
	t_list	*ret;
	int		i;

	i = 1;
	if (!check_error(str[i]))
		return (NULL);
	if (!(ret = ft_lstnew(str[i], ft_strlen(str[i]))))
		return (NULL);
	i++;
	while (i < nb_num)
	{
		if (check_error(str[i]))
			ft_lstadd(&ret, ft_lstnew(str[i], ft_strlen(str[i])));
		i++;
	}
	return (ret);
}

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

t_list	get_pile_a(char *str)
{
	t_list	ret;
	int		i;

	i = 0;
	if (!ft_isdigit(str[i]))
		return (NULL);
	if (!(ret = ft_lstnew(ft_atoi(str[i]), sizeof(int))))
		return (NULL);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			ft_lstadd(&ret, ft_lstnew(ft_atoi(str[i]), sizeof(int)));
		}
		while (ft_isdigit(str[i]))
			i++;
		if (str[i])
		{
			i++;
			if (!ft_isdigit(str[i])
				return (NULL);
		}
	}
	return (ret);
}

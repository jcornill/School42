/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_from_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 14:20:52 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/21 14:21:15 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_nbr_from_back(char *p, int i)
{
	int		val;
	int		j;

	val = 0;
	j = 1;
	while (ft_isdigit(p[i]))
	{
		val += (p[i] - 48) * j;
		j *= 10;
		i--;
	}
	return (val);
}

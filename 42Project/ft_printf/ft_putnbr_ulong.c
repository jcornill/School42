/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ulong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 14:28:38 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/21 14:29:38 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(unsigned long work)
{
	char			c;
	int				val;

	val = 0;
	if (work >= 10)
	{
		val += process(work / 10);
		val += process(work % 10);
	}
	else
	{
		c = '0' + work;
		write(1, &c, 1);
		val += 1;
	}
	return (val);
}

int			ft_putnbr_ulong(unsigned long nb)
{
	return (process(nb));
}

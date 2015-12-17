/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:36:40 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/17 17:25:31 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(long nb)
{
	char    		c;
	int				val;
	unsigned long	work;
	
	val = 0;
	work = nb;
	if (nb < 0)
	{
		nb += 1;
		work = -nb;
		work += 1;
		write(1, "-", 1);
		val += 1;
	}
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

int			ft_putnbr_long(long nb)
{
	return (process(nb));
}

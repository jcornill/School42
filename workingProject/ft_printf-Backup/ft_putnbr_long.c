/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:36:40 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/17 16:25:09 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(long nb)
{
	char    		c;
	int				val;
	unsigned long	work;
	
	val = 0;
	if (nb < 0)
	{
		nb += 1;
		work = -nb;
		work += 1;
	}
	if (nb >= 10)
	{
		val += process(nb / 10);
		val += process(nb % 10);
	}
	else
	{
		c = '0' + nb;
		write(1, &c, 1);
		val += 1;
	}
	return (val);
}

int			ft_putnbr_long(long nb)
{
	process(nb);
}

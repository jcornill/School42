/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 14:21:46 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/21 14:22:50 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_long(long n)
{
	char			c;
	int				val;
	unsigned long	work;

	val = 0;
	work = n;
	if (n < 0)
	{
		n += 1;
		work = -n;
		work += 1;
		val += write(1, "-", 1);
	}
	if (work >= 10)
	{
		val += ft_putnbr_long(work / 10);
		val += ft_putnbr_long(work % 10);
	}
	else
	{
		c = '0' + work;
		write(1, &c, 1);
		val += 1;
	}
	return (val);
}

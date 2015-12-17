/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:42 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/17 23:50:54 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_base_long(unsigned long nb, int base, char a)
{
	char    c;
	int		val;

	val = 0;
	if (nb >= (unsigned long)base)
	{
		val += ft_putnbr_base_long(nb / base, base, a);
		val += ft_putnbr_base_long(nb % base, base, a);
	}
	else
	{
		if (nb >= 10 && a == 0)
			c = 'a' + (nb - 10);
		else if (a == 1 && nb >= 10)
			c = 'A' + (nb - 10);
		else
			c = '0' + nb;
		write(1, &c, 1);
		val += 1;
	}
	return (val);
}

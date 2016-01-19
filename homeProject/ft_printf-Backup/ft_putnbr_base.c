/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:42 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/19 15:35:42 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_base(long nb, int base, char a)
{
	char    c;
	int		val;

	val = 0;
	if (nb < 0)
	{
		nb = -nb;
		val = 1;
	}
	if (nb >= base)
	{
		val += ft_putnbr_base(nb / base, base, a);
		val += ft_putnbr_base(nb % base, base, a);
	}
	else
	{
		if (nb >= 10 && a == 0)
			c = 'a' + (nb - 10);
		else if (a == 1)
			c = 'A' + (nb - 10);
		else
			c = '0' + nb;
		write(1, &c, 1);
		return (val + 1);
	}
	return (val);
}

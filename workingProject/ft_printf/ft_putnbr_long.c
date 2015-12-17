/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:45:55 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/17 19:50:57 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int		ft_putnbr_long(long n)
{
	char	c;
	int		val;
	
	val = 0;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		val += 1;
	}
	if (n >= 10)
	{
		val += ft_putnbr_long(n / 10);
		val += ft_putnbr_long(n % 10);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
		val += 1;
	}
	return (val);
}

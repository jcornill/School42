/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:45:55 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/21 14:30:08 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbrprintf(long n)
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
		val += ft_putnbrprintf(n / 10);
		val += ft_putnbrprintf(n % 10);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
		val += 1;
	}
	return (val);
}

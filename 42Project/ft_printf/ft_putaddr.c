/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:56:11 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/19 15:35:55 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putaddr(long nb)
{
	int		val;

	write(1, "0x", 2);
	val = 2;
	val += ft_putnbr_base(nb, 16, 0);
	return (val);
}

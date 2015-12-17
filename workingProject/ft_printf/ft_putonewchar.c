/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putonewchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 00:30:22 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/18 00:37:33 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putonewchar(wchar_t str)
{
	int		j;
	int		val;
	
	j = -1;
	val = 0;
	if (str == 0)
	{
		write(1, "(null)", 6);
		return (-4);
	}
	while (j++ < 4)
	{
		if (*(&str + j) == 0)
			break ;
		if (*(&str + j) > 255)
			return (-1);
	}
	val += 1;
	j = -1;
	while (++j < 4)
	{
		if (*(&str + j) > 0 && *(&str + j) < 255)
			write(1, (&str + j), 1);
		else
			return (val - 3);
	}
	return (val);
}

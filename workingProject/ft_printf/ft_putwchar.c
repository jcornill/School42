/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:35:01 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/18 00:46:22 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwchar(wchar_t *str)
{
	int		i;
	int		j;
	int		val;
	
	i = 0;
	j = -1;
	val = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (-4);
	}
	while (j++ < 4)
	{
		if (*(str + i + j) == 0)
			break ;
		if (*(str + i + j) > 255)
			return (-1);
	}
	while (*(str + i))
	{
		val += 1;
		j = -1;
		while (++j < 4)
		{
			if (*(str + i + j) > 0 && *(str + i + j) < 255)
				write(1, (str + i + j), 1);
			else
				return (val - 3);
		}
		i += 4;
	}
	return (val);
}

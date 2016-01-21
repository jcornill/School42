/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:35:01 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/21 14:32:17 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwchar(wchar_t *str)
{
	int		i;
	int		val;

	i = 0;
	val = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*(str + i))
	{
		if (*(str + i) > 255)
			return (-1);
		i++;
	}
	i = 0;
	while (*(str + i))
	{
		val += 1;
		if (*(str + i) <= 255)
			write(1, (str + i), 1);
		else
			return (-1);
		i++;
	}
	return (val);
}

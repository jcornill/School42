/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:35:01 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/17 21:56:09 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  void	ft_putwchar(wchar_t *str)
**{
**int		i;
**int		len;
**
**i = 0;
**len = 0;
**while (str[len] > 193 && str[len] < 224 && str[len])
**len += 2;
**if (str[0] < 127)
**len = len;
**else if (str[len] != 0)
**return (;);
**while (str[i])
**{
**write(1, &str[i], 1);
**  write(1, &str[i + 1], 1);
**i += 2;
** }
**  }
*/

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

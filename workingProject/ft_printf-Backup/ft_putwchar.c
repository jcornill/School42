/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:35:01 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/16 15:36:13 by jcornill         ###   ########.fr       */
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

void	ft_putwchar(wchar_t *str)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (j++ < 4)
	{
		if (*(str + i + j) == 0)
			break ;
		if (*(str + i + j) > 255)
			return ;
	}
	while (*(str + i))
	{
		j = -1;
		while (++j < 4)
		{
			if (*(str + i + j) > 0 && *(str + i + j) < 255)
				write(1, (str + i + j), 1);
		}
		i += 4;
	}
}

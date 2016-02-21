/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 14:45:26 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/21 15:13:22 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print(int nb, char c)
{
	while (--nb > 0)
		write(1, &c, 1);
}

static char		init(int t[4], char *param)
{
	t[1] = 1;
	t[2] = 0;
	t[3] = 1;
	t[0] = ft_strlen(param) + 1;
	return (' ');
}

int				get_content_len(void *content, char c)
{
	int		val;

	val = 0;
	if (c == 'p')
		val += 2;
	if (c == 'x' || c == 'X' || c == 'p')
		val += ft_nbrlen((long)content, 16);
	else if (c == 'o' || c == 'O')
		val += ft_nbrlen((long)content, 8);
	else if (c == 's' || c == 'S')
		val += ft_strlen((char *)content);
	else
		val += ft_nbrlen((long)content, 10);
	return (val);
}

int				ft_write_space(char *param, void *content, char c, int k)
{
	int		t[4];
	char	ch;

	ch = init(t, param);
	while (--t[0] > 0)
	{
		if (ft_isdigit(param[t[0]]))
		{
			t[2] += (param[t[0]] - 48) * t[1];
			t[1] *= 10;
		}
		else if (param[t[0]] == '-')
			t[3] = -1;
		if (param[t[0]] == '0' && t[2] > 0)
			ch = '0';
	}
	t[2] -= get_content_len(content, c);
	if (t[3] == 1 || k)
		print(t[2] + 1, ch);
	t[2] = (t[2] < 0) ? 0 : t[2];
	t[3] = (t[3] == -1 && k) ? 1 : t[3];
	return (t[2] * t[3]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_norme.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:32:01 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/21 15:59:39 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long		get_number(char c, void *content)
{
	if (c == 'd' || c == 'i')
		return ((int)content);
	else if (c == 'p' || c == 'D')
		return ((long)content);
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'b')
		return ((unsigned int)content);
	return (0);
}

static int		print(unsigned long unumber, char c, char *str, long t[4])
{
	if (t[3] >= 0)
	{
		if (c == 'S' || c == 's')
			return (print_arg_str(str, c) + t[3]);
		else if (t[2])
			return (print_arg_unb(unumber, c) + t[3]);
		else
			return (print_arg_nb(t[0], c) + t[3]);
	}
	return (0);
}

static int		process(char *p, long t[4], char c, void *content)
{
	if (p[t[1]] == 'h' && p[t[1] - 1] != 'h' &&
		(c == 'u' || c == 'x' || c == 'o' || c == 'X' || c == 'D' || c == 'b'))
		t[0] = (unsigned short)content;
	else if (p[t[1]] == 'h' && p[t[1] - 1] != 'h')
		t[0] = (short)content;
	else if (p[t[1]] == 'h' && p[t[1] - 1] == 'h' &&
		(c == 'u' || c == 'x' || c == 'o' || c == 'X'))
		t[0] = (unsigned char)content;
	else if (p[t[1]] == 'h' && p[t[1] - 1] == 'h' && c == 'D')
		t[0] = (unsigned short)content;
	else if (p[t[1]] == 'h' && p[t[1] - 1] == 'h')
		t[0] = (char)content;
	else if (ft_isdigit(p[t[1]]) && !ft_isdigit(p[t[1] - 1]) &&
			ft_strchr(p, '.') == 0)
		t[3] += ft_write_space(p, content, c, 0);
	else if (p[t[1]] == '#')
		t[3] += process_sharp(content, c);
	else if (p[t[1]] == '+' && c != 's' && c != 'S')
		t[3] += process_add(content, c);
	else if (p[t[1]] == ' ' && c != 's' && c != 'S' && c != 'c' &&
			c != 'C' && !ft_strchr(p, '+'))
		t[3] += process_space(content, c);
	return (0);
}

static char		*init_var(long t[4], char c, void *content)
{
	t[0] = get_number(c, content);
	t[2] = 0;
	t[3] = 0;
	return (0);
}

int				p_arg(void *cnt, char *p, char c)
{
	char			*str;
	long			t[5];
	unsigned long	unumber;

	if ((str = init_var(t, c, cnt)) == 0 && (c == 'S' || c == 'c' || c == 'C'))
		return (process_2(c, cnt));
	unumber = process_3(c, &str, cnt, t);
	if ((t[1] = 0) == 0 && ft_strlen(p) > 2)
	{
		while (p[++t[1]] != c)
			if (p[t[1]] == '.' && c != 's' && c != 'S')
				t[3] += process_point(cnt, c, p, t[1]);
			else if (p[t[1]] == '.')
				t[3] += process_point_str(str, p, t[1]);
			else if ((p[t[1]] == 'l' || p[t[1]] == 'j') && (c != 'u' &&
					c != 'o' && c != 'x') && p[t[1] - 1] != 'l')
				t[0] = (long)cnt;
			else if (((p[t[1]] == 'l' && t[0] > 0) ||
					p[t[1]] == 'j' || p[t[1]] == 'z') && (t[2] = 1) == 1)
				unumber = (unsigned long)cnt;
			else
				process(p, t, c, cnt);
	}
	return ((t[3] < 0) ? (print_arg_nb(t[0], c) + ft_write_space(p, cnt,
			c, 1)) : print(unumber, c, str, t));
}

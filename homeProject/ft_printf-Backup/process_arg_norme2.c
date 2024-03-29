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
		ft_strchr(p, '.') == NULL)
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

int				process_arg(void *cont, char *p, char c)
{
	char			*str;
	long			t[5];
	unsigned long	unumber;

	if ((str = init_var(t, c, cont)) == 0 && (c == 'S' || c == 'c' || c == 'C')
		return (process_2(c, cont));
	else if (c == 's' || c == '%')
		str = (char *)cont;
	else if ((c == 'O' || c == 'U') && (t[2] = 1) == 1)
		unumber = (unsigned long)cont;
	if ((t[1] = 0) == 0 && ft_strlen(p) > 2)
		while (p[++t[1]] != c)
			if (p[t[1]] == '.' && c != 's' && c != 'S')
				t[3] += process_point(cont, c, p, t[1]);
			else if (p[t[1]] == '.')
				t[3] += process_point_str(str, p, t[1]);
			else if ((p[t[1]] == 'l' || p[t[1]] == 'j') && (c != 'u' &&
				c != 'o' && c != 'x') && p[t[1] - 1] != 'l')
				t[0] = (long)cont;
			else if (((p[t[1]] == 'l' && t[0] > 0) ||
				p[t[1]] == 'j' || p[t[1]] == 'z') && (t[2] = 1) == 1)
				unumber = (unsigned long)cont;
			else
				process(p, t, c, cont);
	if (t[3] < 0)
		return (print_arg_nb(t[0], c) + ft_write_space(p, cont, c, 1));
	return (print(unumber, c, str, t));
}

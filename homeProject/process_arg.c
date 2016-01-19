#include "ft_printf.h"

static int	get_number(char c, void *content)
{
		if (c == 'd' || c == 'i')
			return ((int)content);
		else if (c == 'p' || c == 'D')
			return ((long)content);
		else if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'b')
			return ((unsigned int)content);
		return (0);
}

int			process_arg(void *content, char *p, char c)
{
	char			*str;
	long			number;
	unsigned long	unumber;
	int				i;
	int				ulong;
	int				val;

	str = 0;
	number = get_number(c, content);
	unumber = 0;
	ulong = 0;
	val = 0;
	if (c == 'S')
		return (ft_putwchar((wchar_t *)content));
	else if (c == 'c')
		return (write(1, &content, 1));
	else if (c == 'C')
		return (ft_putonewchar((wchar_t)content));
	else if (c == 's' || c == '%')
		str = (char *)content;
	else if (c == 'O' || c == 'U')
	{
		unumber = (unsigned long)content;
		ulong = 1;
	}
	if (ft_strlen(p) > 2)
	{
		i = 1;
		while (p[i] != c)
		{
			if ((p[i] == 'l' || p[i] == 'j') && (c != 'u' || c != 'o' || c != 'x'))
				number = (long)content;
			else if (p[i] == 'l' || p[i] == 'j' || p[i] == 'z')
			{
				unumber = (unsigned long)content;
				ulong = 1;
			}
			else if (p[i] == 'h' && p[i - 1] != 'h' &&
				(c == 'u' || c == 'x' || c == 'o' || c == 'X' || c == 'D' || c == 'b'))
				number = (unsigned short)content;
			else if (p[i] == 'h' && p[i - 1] != 'h')
				number = (short)content;
			else if (p[i] == 'h' && p[i - 1] == 'h' &&
				(c == 'u' || c == 'x' || c == 'o' || c == 'X'))
				number = (unsigned char)content;
			else if (p[i] == 'h' && p[i - 1] == 'h' && c == 'D')
				number = (unsigned short)content;
			else if (p[i] == 'h' && p[i - 1] == 'h')
				number = (char)content;
			else if (ft_isdigit(p[i]) && !ft_isdigit(p[i - 1]) && ft_strchr(p, '.') == NULL)
				val += ft_write_space(p, content, c, 0);
			else if (p[i] == '#')
				val += process_sharp(content, c);
			else if (p[i] == '+' && c != 's' && c != 'S')
				val += process_add(content, c);
			else if (p[i] == ' ' && c != 's' && c != 'S' && c != 'c' && c != 'C' && ft_strchr(p, '+') == NULL)
				val += process_space(content, c);
			else if (p[i] == '.' && c != 's' && c != 'S')
				val += process_point(content, c, p, i);
			else if (p[i] == '.')
				val += process_point_str(str, p, i);
			i++;
		}
	}
	if (val >= 0)
	{
		if (c == 'S' || c == 's')
			return (print_arg_str(str, c) + val);
		else if (ulong)
			return (print_arg_unb(unumber, c) + val);
		else
			return (print_arg_nb(number, c) + val);
	}
	if (val < 0)
	{
		ulong = print_arg_nb(number, c);
		val = ft_write_space(p, content, c, 1);
		return (val + ulong);
	}
	return (0);
}
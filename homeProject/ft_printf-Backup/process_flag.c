#include "ft_printf.h"

int		process_sharp(void *content, char c)
{
	if ((c == 'o' || c == 'O') && (long)content != 0)
		return (write(1, "0", 1));
	else if (c == 'x' && (long)content != 0)
		return (write(1, "0x", 2));
	else if (c == 'X' && (long)content != 0)
		return (write(1, "0X", 2));
	return (0);
}

int		process_add(void *content, char c)
{
	if ((long)content >= 0 && c != 'o' && c != 'O')
		return (write(1, "+", 1));
	return (0);
}

int		process_space(void *content, char c)
{
	if ((long)content >= 0 && c != 'u')
		return (write(1, " ", 1));
	return (0);
}

int		process_point(void *content, char c, char *param, int i)
{
	int		val1;
	int		val2;
	int		j;
	int		result;

	val1 = 0;
	val2 = 0;
	result = 0;
	if (ft_isdigit(param[i - 1]))
		val1 = ft_get_nbr_from_back(param, i - 1);
	if (ft_isdigit(param[i + 1]))
		val2 = ft_atoi(&param[i + 1]);
	if (val2 > get_content_len(content, c))
		j = val1 - val2;
	else
		j = val1 - get_content_len(content, c);
	while (--j >= 0)
		result += write(1, " ", 1);
	j = (val2 - get_content_len(content, c));
	while (--j >= 0 && c != 's' && c != 'S')
		result += write(1, "0", 1);
	return (result);
}

int		process_point_str(char *str, char *param, int i)
{
	int		val1;
	int		val2;
	int		j;
	int		result;

	val1 = 0;
	val2 = 0;
	result = 0;
	if (ft_isdigit(param[i - 1]))
		val1 = ft_get_nbr_from_back(param, i - 1);
	if (ft_isdigit(param[i + 1]))
		val2 = ft_atoi(&param[i + 1]);
	if (val2 > (int)ft_strlen(str))
		j = val1 - val2 + val2 - ft_strlen(str);
	else
		j = val1 - (int)ft_strlen(str);
	while (--j >= 0)
		result += write(1, " ", 1);
	return (result);
}

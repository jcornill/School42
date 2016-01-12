
#include "ft_printf.h"

static void	print(int nb, char c)
{
	while (--nb > 0)
		write(1, &c, 1);
}

int			get_content_len(void *content, char c)
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

int			ft_write_space(char *param, void *content, char c, int k)
{
	int		i;
	int		j;
	int		val;
	int		neg;
	char	ch;

	j = 1;
	val = 0;
	neg = 1;
	ch = ' ';
	i = ft_strlen(param);
	while (i > 0)
	{
		if (ft_isdigit(param[i]))
		{
			val += (param[i] - 48) * j;
			j *= 10;
		}
		else if (param[i] == '-')
			neg = -1;
		if (param[i] == '0' && val > 0)
			ch = '0';
		i--;
	}
	val -= get_content_len(content, c);
	if (neg == 1 || k)
		print(val + 1, ch);
	if (val < 0)
		val = 0;
	if (neg == -1 && k)
		neg = 1;
	return (val * neg);
}
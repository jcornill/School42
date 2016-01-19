#include "ft_printf.h"

static int	print_color(char *color, int i)
{
	if (!ft_strcmp(color, "red"))
		return (write(1, "\033[31m", 5) * 0 + i + 1);
	else if (!ft_strcmp(color, "lred"))
		return (write(1, "\033[1;31m", 7) * 0 + i + 1);
	else if (!ft_strcmp(color, "green"))
		return (write(1, "\033[32m", 5) * 0 + i + 1);
	else if (!ft_strcmp(color, "black"))
		return (write(1, "\033[30m", 5) * 0 + i + 1);
	else if (!ft_strcmp(color, "yellow"))
		return (write(1, "\033[33m", 5) * 0 + i + 1);
	else if (!ft_strcmp(color, "blue"))
		return (write(1, "\033[34m", 5) * 0 + i + 1);
	else if (!ft_strcmp(color, "purple"))
		return (write(1, "\033[35m", 5) * 0 + i + 1);
	else if (!ft_strcmp(color, "cyan"))
		return (write(1, "\033[36m", 5) * 0 + i + 1);
	else if (!ft_strcmp(color, "eof"))
		return (write(1, "\033[0m", 4) * 0 + i + 1);
	return (0);
}

int			process_color(char *s)
{
	int			i;
	static char	*color = NULL;

	i = 0;
	while (s[i] != 0 && s[i] != '}')
		i++;
	if (s[i] == 0)
		return (0);
	if (color != NULL)
		ft_memdel((void **)&color);
	color = ft_strdup((const char*)&s[1]);
	color[i - 1] = 0;
	return (print_color(color, i));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:10:40 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/18 00:06:21 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_arg(char *str)
{
	if (str[0] != '%')
		return (0);
	if (str[1] == 's')
		return ("%s");
	else if (str[1] == 'd')
		return ("%d");
	else if (str[1] == 'i')
		return ("%i");
	else if (str[1] == 'p')
		return ("%p");
	else if (str[1] == '%')
		return ("%%");
	else if (str[1] == 'S')
		return ("%S");
	else if (str[1] == 'D')
		return ("%D");
	else if (str[1] == 'o')
		return ("%o");
	else if (str[1] == 'O')
		return ("%O");
	else if (str[1] == 'u')
		return ("%u");
	else if (str[1] == 'U')
		return ("%U");
	else if (str[1] == 'x')
		return ("%x");
	else if (str[1] == 'X')
		return ("%X");
	else if (str[i] == 'c')
		return ("%c");
	return (0);
}

int		print_arg(void *str, char *param)
{
	if (!ft_strcmp("%s", param))
		return (ft_putstrprintf(str));
	else if (!ft_strcmp("%d", param) || !ft_strcmp("%i", param))
		return (ft_putnbr_long((int)str));
	else if (!ft_strcmp("%p", param))
		return (ft_putaddr((long)str));
	else if (!ft_strcmp("%%", param))
		return (ft_putstrprintf("%"));
	else if (!ft_strcmp("%S", param))
		return (ft_putwchar((wchar_t *)str));
	else if (!ft_strcmp("%D", param))
		return (ft_putnbr_long((long)str));
	else if (!ft_strcmp("%o", param))
		return (ft_putnbr_base((unsigned int)str, 8, 0));
	else if (!ft_strcmp("%O", param))
		return (ft_putnbr_base_long((unsigned long)str, 8, 0));
	else if (!ft_strcmp("%u", param))
		return (ft_putnbr_long((unsigned int)str));
	else if (!ft_strcmp("%U", param))
		return (ft_putnbr_ulong((unsigned long)str));
	else if (!ft_strcmp("%x", param))
		return (ft_putnbr_base((unsigned int)str, 16, 0));
	else if (!ft_strcmp("%X", param))
		return (ft_putnbr_base_long((unsigned int)str, 16, 1));
	return (0);
}

int		process_input(char *str, char **param)
{
	int		len;

	len = 0;
	while (str[len])
	{
		if (((*param) = get_arg(&str[len])) != 0)
			return (ft_strlenstr(str, (*param)));
		len++;
	}
	return (ft_strlen(str));
}

int		ft_printf(char *str, ...)
{
	va_list		args;
	size_t		val;
	int			compteur;
	int			len;
	char		*param;
	int			written_char;
	int			temp;
	
	compteur = 0;
	written_char = 0;
	va_start(args, str);
	len = ft_strlen(str);
	param = NULL;
	while (compteur < len)
	{
		if (compteur != 0)
			str = &str[val + 2];
		val = process_input(str, &param);
		if (param != NULL)
			compteur += val + ft_strlen(param);
		else
			compteur += val + 2;
		written_char += val;
		write(1, str, val);
		temp = 0;
		if (val != ft_strlen(str))
			temp = print_arg(va_arg(args, void *), param);
		if (temp == -1)
			return (-1);
		written_char += temp;
	}
	va_end(args);
	return (written_char);
}

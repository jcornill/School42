/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:10:40 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/19 19:41:30 by jcornill         ###   ########.fr       */
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
	else if (str[1] == 'c')
		return ("%c");
	else if (str[1] == 'C')
		return ("%C");
	else if (str[1] == 'l' && str[2] == 'd')
		return ("%ld");
	else if (str[1] == 'l' && str[2] == 'i')
		return ("%li");
	else if (str[1] == 'l' && str[2] == 'u')
		return ("%lu");
	else if (str[1] == 'l' && str[2] == 'o')
		return ("%lo");
	else if (str[1] == 'l' && str[2] == 'x')
		return ("%lx");
	else if (str[1] == 'l' && str[2] == 'X')
		return ("%lX");
	else if (str[1] == 'l' && str[2] == 'c')
		return ("%lc");
	else if (str[1] == 'l' && str[2] == 's')
		return ("%ls");
	else if (str[1] == 'l' && str[2] == 'O')
		return ("%lO");
	else if (str[1] == 'l' && str[2] == 'U')
		return ("%lU");
	else if (str[1] == 'l' && str[2] == 'D')
		return ("%lD");
	else if (str[1] == 'l' && str[2] == 'l' && str[3] == 'd')
		return ("%lld");
	else if (str[1] == 'l' && str[2] == 'l' && str[3] == 'i')
		return ("%lli");
	else if (str[1] == 'l' && str[2] == 'l' && str[3] == 'u')
		return ("%llu");
	else if (str[1] == 'l' && str[2] == 'l' && str[3] == 'o')
		return ("%llo");
	return ("%");
}

int		print_arg(void *str, char *param)
{
	if (!ft_strcmp("%s", param))
		return (ft_putstrprintf(str));
	else if (!ft_strcmp("%d", param) || !ft_strcmp("%i", param))
		return (ft_putnbr_long((int)str));
	else if (!ft_strcmp("%ld", param) || !ft_strcmp("%li", param) || !ft_strcmp("%lld", param) || !ft_strcmp("%lli", param))
		return (ft_putnbr_long((long)str));
	else if (!ft_strcmp("%p", param))
		return (ft_putaddr((long)str));
	else if (!ft_strcmp("%%", param))
		return (ft_putstrprintf("%"));
	else if (!ft_strcmp("%S", param) || !ft_strcmp("%ls", param))
		return (ft_putwchar((wchar_t *)str));
	else if (!ft_strcmp("%D", param))
		return (ft_putnbr_long((long)str));
	else if (!ft_strcmp("%o", param))
		return (ft_putnbr_base((unsigned int)str, 8, 0));
	else if (!ft_strcmp("%O", param) || !ft_strcmp("%lo", param) || !ft_strcmp("%llo", param))
		return (ft_putnbr_base_long((unsigned long)str, 8, 0));
	else if (!ft_strcmp("%u", param))
		return (ft_putnbr_long((unsigned int)str));
	else if (!ft_strcmp("%U", param) || !ft_strcmp("%lu", param) || !ft_strcmp("%llu", param))
		return (ft_putnbr_ulong((unsigned long)str));
	else if (!ft_strcmp("%x", param))
		return (ft_putnbr_base((unsigned int)str, 16, 0));
	else if (!ft_strcmp("%X", param))
		return (ft_putnbr_base_long((unsigned int)str, 16, 1));
	else if (!ft_strcmp("%lx", param))
		return (ft_putnbr_base_long((unsigned long)str, 16, 0));
	else if (!ft_strcmp("%lX", param))
		return (ft_putnbr_base_long((unsigned long)str, 16, 1));
	else if (!ft_strcmp("%c", param))
		return (write(1, &str, 1));
	else if (!ft_strcmp("%C", param) || !ft_strcmp("%lc", param))
		return (ft_putonewchar((wchar_t)str));
	else if (!ft_strcmp("%lO", param))
		return (ft_putnbr_base_long((unsigned long)str, 8, 0) * 0 - 1);
	else if (!ft_strcmp("%lU", param))
		return (ft_putnbr_ulong((unsigned long)str) * 0 - 1);
	else if (!ft_strcmp("%lD", param))
		return (ft_putnbr_long((long)str) * 0 - 1);
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
	int			temple;
	
	compteur = 0;
	written_char = 0;
	va_start(args, str);
	len = ft_strlen(str);
	param = NULL;
	temple = 0;
	temp = 0;
	while (compteur < len)
	{
		if (compteur != 0)
			str = &str[val + temple];
		val = process_input(str, &param);
		if (param != NULL)
		{
			compteur += val + ft_strlen(param);
			temple = ft_strlen(param);
		}
		else
			compteur += val + 2;
		written_char += val;
		write(1, str, val);
		temp = 0;
		if (val != ft_strlen(str))
			temp = print_arg(va_arg(args, void *), param);
		if (temp == -1 && (!ft_strcmp(param, "%S") || !ft_strcmp(param, "%C") || !ft_strcmp(param, "%ls") || !ft_strcmp(param, "%lc")))
			return (-1);
		written_char += temp;
		if (temp == -1)
			written_char = temp - 1;
	}
	va_end(args);
	return (written_char);
}

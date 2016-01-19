/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:10:40 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/19 15:40:43 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		process_convertion(char *s, char **param, int *i)
{
	while (s[*i])
	{
		if (s[*i] == 's' || s[*i] == 'd' || s[*i] == '%' || s[*i] == 'p' ||
			s[*i] == 'S' || s[*i] == 'D' || s[*i] == 'i' || s[*i] == 'o' ||
			s[*i] == 'O' || s[*i] == 'u' || s[*i] == 'U' || s[*i] == 'x' ||
			s[*i] == 'X' || s[*i] == 'c' || s[*i] == 'C' || s[*i] == 'b')
		{
			(*param) = ft_strnew((*i) + 1);
			(*param)[0] = '%';
			ft_strncpy(&(*param)[1], &s[1], *i);
			return (1);
		}
		if (s[*i] == '#' || s[*i] == '0' || s[*i] == '-' || s[*i] == '+' ||
			s[*i] == ' ' || s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'j' ||
			s[*i] == 'z' || s[*i] == '.' || ft_isdigit(s[*i]))
			(*i)++;
		else
			break;
	}
	return (0);
}

static char	*search_convertion(char *s)
{
	char	*param;
	int		i;

	i = 1;
	if (process_convertion(s, &param, &i))
		return (param);
	param = ft_strnew(i + 1);
	param[0] = '%';
	if (i > 1)
		ft_strncpy(&param[1], &s[i - 1], i - 1);
	return (param);
}

static int init(char *str, int *i, char **param)
{
	if (str[*i] == '{')
		(*i) += process_color(&str[*i]);
	if (str[*i] == '%')
		(*param) = search_convertion(&str[*i]);
	else
		(*param) = NULL;
	return (1);
}

int			ft_printf(char *str, ...)
{
	va_list		args;
	int			i;
	int			written_char;
	char		*param;
	int			temp;

	i = -1;
	written_char = 0;
	va_start(args, str);
	param = NULL;
	while (str[++i])
		if (init(str, &i, &param) && param != NULL)
		{
			if (ft_strlen(param) > 1)
			{
				if (param[ft_strlen(param) - 1] != '%')
					temp = process_arg(va_arg(args, void *), param, param[ft_strlen(param) - 1]);
				else
					temp = write(1, "%", 1);
				if (temp == -1)
					return (-1);
				else
					written_char += temp;
				i += ft_strlen(param) - 1;
			}
		}
		else
			written_char += write(1, &str[i], 1);
	va_end(args);
	return (written_char);
}

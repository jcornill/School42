/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:01:06 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/21 16:01:09 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					process_2(char c, void *content)
{
	if (c == 'S')
		return (ft_putwchar((wchar_t *)content));
	else if (c == 'c')
		return (write(1, &content, 1));
	else if (c == 'C')
		return (ft_putonewchar((wchar_t)content));
	return (0);
}

unsigned long		process_3(char c, char **str, void *content, long t[5])
{
	if (c == 's' || c == '%')
		*str = (char *)content;
	else if (c == 'O' || c == 'U')
		t[2] = 1;
	return ((unsigned long)content);
}

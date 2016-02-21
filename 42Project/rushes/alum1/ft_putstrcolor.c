/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcolor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:18:02 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/20 15:29:09 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		ft_putstrcolor(char *str, char *color_code)
{
	int		val;

	val = 0;
	val += write(1, "\033[", 2);
	val += write(1, color_code, ft_strlen(color_code));
	val += write(1, "m", 1);
	val += write(1, str, ft_strlen(str));
	val += write(1, "\033[0m", 4);
	return (val);
}

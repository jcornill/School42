/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putonewchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 00:30:22 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/19 17:21:01 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putonewchar(wchar_t str)
{
	if (str == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (str > 0 && str <= 255)
		write(1, &str, 1);
	else
		return (-1);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:33:07 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/11 18:50:45 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void	ft_putchar_fd_unsigned(unsigned short c, int fd)
{
	write(fd, (void*)&c, 1);

}

int		main(void)
{
	ft_printf("Bonjour %s %s %s%s%s%s\n", "tout", "le", "m", "on", "d", "e");
	//wchar_t test[50] = {195, 169};
	//printf("%S\n", test);
	//ft_putchar_fd_unsigned(test[0], 1);
	//ft_putchar_fd_unsigned(test[1], 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 15:40:47 by jcornill          #+#    #+#             */
/*   Updated: 2016/04/18 15:51:45 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

#include <fcntl.h>

int		main(void)
{
	char	buf[3000];
	int		fd;
	int		i;
	int		r;

	fd = open("file2", O_RDONLY);
	r = read(fd, buf, 3000);
	i = 0;
	while (i < r)
	{
		if (buf[i] == 0)
			ft_putchar('0');
		else
			ft_putchar('1');
		i++;
	}
	return (0);
}

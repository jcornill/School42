/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 15:40:47 by jcornill          #+#    #+#             */
/*   Updated: 2016/04/20 18:33:27 by jcornill         ###   ########.fr       */
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
		else if (buf[i] < 10)
			ft_putchar(buf[i] + 48);
		else
			ft_putchar(buf[i] + 'a');
		i++;
	}
	return (0);
}

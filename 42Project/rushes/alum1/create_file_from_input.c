/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_from_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:40:44 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/20 14:44:32 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		create_file_from_input(void)
{
	int		fd;
	char	buf[1];

	if ((fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC)) == -1)
		return (-1);
	while (1)
	{
		if (read(0, buf, 1) == -1)
			return (-1);
		if (buf[0] == '\n')
		{
			write(fd, buf, 1);
			if (read(0, buf, 1) == -1)
				return (-1);
			if (buf[0] == '\n')
				break ;
		}
		write(fd, buf, 1);
	}
	close(fd);
	return (0);
}

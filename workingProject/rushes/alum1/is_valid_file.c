/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:21:06 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/20 18:09:55 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		is_valid_file(char *file)
{
	int		fd;
	int		byte_read;
	char	buf[50 + 1];
	int		i;
	int		line;

	line = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while ((byte_read = read(fd, buf, 50)))
	{
		if ((buf[byte_read] = 0) == 0 && byte_read == -1)
			return (-2);
		if ((i = -1) == -1 && line == 0 && !ft_isdigit(buf[0]))
			return (-3);
		while (buf[++i])
			if (!ft_isdigit(buf[i]))
			{
				if (buf[i] == '\n')
					line++;
				else
					return (-4);
			}
	}
	return ((buf[i - 1] != '\n') ? -5 : line);
}

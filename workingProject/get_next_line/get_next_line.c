/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:09:45 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/08 18:57:42 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		process_line(int byte_read, char *buf, char **line, int cursor)
{
	int		i;
	i = 0;
	while (i < byte_read)
	{
		if (buf[i] == '\n')
			return (byte_read - i - 1);
		if (!(*line))
			if (!((*line) = (char *)malloc(sizeof(char) * (cursor + byte_read))))
				return (0);
		(*line)[cursor + i] = buf[i];
		i++;
		(*line)[cursor + i] = 0;
	}
	return (-1);
}

static int		read_file(int const fd, char **line, char **test)
{
	int		byte_read;
	char	buf[BUFF_SIZE + 1];
	int		cursor;
	int		char_left;

	cursor = 0;
	char_left = 0;
	while (*test)
	{
		char_left = process_line(ft_strlen(*test), *test, line, cursor);
		cursor += ft_strlen(*test);
		if (char_left > 0)
		{
			*test = ft_strdup(&((*test)[cursor - char_left]));
			return (1);
		}
		else if (char_left == 0)
		{
			*test = NULL;
			return (1);
		}
		else
			*test = NULL;
	}
	while ((byte_read = read(fd, buf, BUFF_SIZE)))
	{
//		printf(" Reading %d", buf[0]);
		if (byte_read == -1)
			return (-1);
		buf[byte_read] = 0;
		char_left = process_line(byte_read, buf, line, cursor);
		cursor += byte_read;
		if (char_left > 0)
		{
			*test = ft_strdup(&buf[byte_read - char_left]);
			return (1);
		}
		else
			*test = NULL;
		if (char_left != -1)
			return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int			read;
	static char	*test = NULL;

	if (line)
		(*line) = NULL;
	else
		return (-1);
	if ((read = read_file(fd, line, &test)) == -1)
		return (-1);
	else if (read)
		return (1);
	return (0);
}

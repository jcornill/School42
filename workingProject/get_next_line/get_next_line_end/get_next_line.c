/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:09:45 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/09 23:31:34 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		process_line(int byte_read, char *buf, char **line, int c)
{
	int		i;

	i = 0;
	while (i < byte_read)
	{
		if (buf[i] == '\n' && !(*line))
		{
			(*line) = ft_strdup("");
			return (byte_read - i - 1);
		}
		if (buf[i] == '\n')
			return (byte_read - i - 1);
		if (!(*line))
			if (!((*line) = (char *)malloc(sizeof(char) * (c + byte_read + 1))))
				return (0);
		(*line)[c + i] = buf[i];
		i++;
		(*line)[c + i] = 0;
	}
	return (-1);
}

static int		process_buf(int *c, char **test, int *cursor, char **line)
{
	while (*test)
	{
		*c = process_line(ft_strlen(*test), *test, line, *cursor);
		(*cursor) += ft_strlen(*test);
		if (*c > 0)
		{
			*test = ft_strdup((*test) + (*cursor - *c));
			return (1);
		}
		else if (*c == 0)
		{
			*test = NULL;
			return (1);
		}
		*test = NULL;
	}
	return (0);
}

static int		read_file(int const fd, char **line, char **test, int c)
{
	int		byte_read;
	char	buf[BUFF_SIZE + 1];
	int		char_left;

	char_left = 0;
	if (process_buf(&char_left, test, &c, line))
		return (1);
	while ((byte_read = read(fd, buf, BUFF_SIZE)))
	{
		if (byte_read == -1)
			return (-1);
		buf[byte_read] = 0;
		char_left = process_line(byte_read, buf, line, c);
		c += byte_read;
		if (char_left > 0)
			if (BUFF_SIZE > ft_strlen((*line)) * 2)
				(*test) = ft_strdup(buf + (byte_read - char_left));
			else
				(*test) = buf + (byte_read - char_left);
		else if (char_left == 0)
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
	if ((read = read_file(fd, line, &test, 0)) == -1)
		return (-1);
	else if (read)
		return (1);
	return (0);
}

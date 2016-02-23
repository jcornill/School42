/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:09:45 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/15 15:53:04 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		process_line(int byte_read, char *buf, char **line, int c)
{
	int		j;
	char	*tmp;

	j = 0;
	while (buf[j] && buf[j] != '\n')
		j++;
	if (!(*line))
		ft_memdel((void **)line);
	if (c == 0)
		(*line) = ft_strdup("");
	if (j)
	{
		tmp = ft_strnew(j);
		ft_strncpy(tmp, buf, j);
		(*line) = ft_strjoin((*line), tmp);
		ft_memdel((void **)&tmp);
	}
	return (byte_read - j - 1);
}

static int		process_buf(int *c, char **test, int *cursor, char **line)
{
	while (*test)
	{
		*c = process_line(ft_strlen(*test), *test, line, *c);
		(*cursor) += ft_strlen(*test);
		if (*c > 0)
		{
			(*test) = ft_strdup((*test) + (*cursor - *c));
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

	if ((char_left = 0) == 0 && process_buf(&char_left, test, &c, line))
		return (1);
	while ((byte_read = read(fd, buf, BUFF_SIZE)))
	{
		if ((buf[byte_read] = 0) == 0 && byte_read == -1)
			return (-1);
		char_left = process_line(byte_read, buf, line, c);
		c += byte_read;
		if (char_left > 0)
		{
			if (!(*test))
				ft_memdel((void **)test);
			(*test) = ft_strnew(char_left);
			ft_strncpy((*test), buf + (byte_read - char_left), char_left);
		}
		else if (char_left == 0)
			ft_memdel((void **)test);
		if (char_left != -1)
			return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int			read;
	static char	*test[100] = {NULL};

	if (line)
		(*line) = NULL;
	else
		return (-1);
	if ((read = read_file(fd, line, &(test[fd]), 0)) == -1)
		return (-1);
	else if (read)
		return (1);
	return (0);
}

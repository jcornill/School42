/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:09:45 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/30 21:30:31 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <stdio.h>

static void		process_line(char *memory, char *buf, int line_len)
{
	ft_strncpy(memory, buf, line_len);
	memory[line_len] = 0;
}

static char		*read_line(char *buf, char *mem, int byte_read, int *temp)
{
	int		line_len;
	char	*memory;

	line_len = 0;
	while (buf[line_len] != '\n' && buf[line_len] != 26 && line_len < byte_read)
		line_len++;
	byte_read -= line_len;
	printf("line_len : %d\n", line_len);
	printf("!%d!\n", byte_read);
	printf("%p**\n", mem);
	if (mem != 0)
	{
		if (!(memory = (char *)malloc(ft_strlen(mem) + line_len + 1)))
			return (NULL);
		process_line(memory, buf, line_len);
		ft_strncat(memory, mem, line_len);
		free(mem);
		mem = memory;
	}
	else
	{
		if (!(memory = (char *)malloc(line_len + 1)))
			return (NULL);
		process_line(memory, buf, line_len);
		mem = memory;
		printf("%p*\n", mem);
	}
	if (byte_read <= 0 && *temp >= 1)
		return (0);
	return (mem);
}

static int		read_file(int const fd, char **line)
{
	char	*buf;
	int		byte_read;
	char	*mem;
	int		temp;

	line = 0;
	temp = 0;
	mem = 0;
	byte_read = 0;
	if (!(buf = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	while ((mem = read_line(buf, mem, byte_read, &temp)))
	{
		byte_read = read(fd, buf, BUFF_SIZE);
		if (byte_read == -1)
			return (-1);
		temp++;
	}
	printf("**%p**\n", mem);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	if (read_file(fd, line) == -1)
		return (-1);
	return (0);
}

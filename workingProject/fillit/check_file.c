/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:53:32 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/03 17:55:16 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_file.h"
#include "fillit.h"
#include "libft.h"

/*
** Fonction qui check si la map est bien de 4 * 4
*/

static int	is_four_square(char *file)
{
	int		fd;
	char	buf[22];
	int		i;
	int		byte_read;

	OPEN(file, fd);
	while ((byte_read = read(fd, buf, 21)))
	{
		i = -1;
		while (++i < 20)
		{
			if (!(((i % 5 == 4 && i != 0) || i == 20) ^ (buf[i] != '\n')))
			{
				close(fd);
				return (0);
			}
		}
		ft_bzero(buf, 20);
	}
	close(fd);
	return (1);
}

static int	has_four_blocks(char *file)
{
	int		fd;
	char	buf[22];
	int		i;
	int		blocs;

	OPEN(file, fd);
	while (read(fd, buf, 21))
	{
		blocs = 0;
		i = -1;
		while (buf[++i])
			if (buf[i] == '#')
			{
				blocs++;
			}
		if (blocs != 4)
		{
			close(fd);
			return (0);
		}
	}
	close(fd);
	return (1);
}

static int	has_valid_number(char *file)
{
	int		fd;
	char	buf[22];
	int		tetriminos;

	OPEN(file, fd);
	tetriminos = 0;
	while (read(fd, buf, 20))
		tetriminos++;
	close(fd);
	return (tetriminos <= 26);
}

static int	contains_valid_char(char *file)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		parser;
	int		byte_read;

	OPEN(file, fd);
	while ((byte_read = read(fd, buf, BUFF_SIZE)))
	{
		parser = 0;
		while (parser < byte_read)
		{
			if (buf[parser] != '.' && buf[parser] != '#'
					&& buf[parser] != '\n')
			{
				close(fd);
				return (0);
			}
			parser++;
		}
	}
	close(fd);
	return (1);
}

int			is_valid_file(char *file)
{
	return (contains_valid_char(file)
			&& is_four_square(file)
			&& has_four_blocks(file)
			&& has_valid_number(file));
}

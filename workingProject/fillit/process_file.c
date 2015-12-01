/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:35:18 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/01 22:47:55 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		get_nbr_tetriminos(char *file)
{
	int		nbr_tetriminos;
	int		byte_read;
	char	buf[21];
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	nbr_tetriminos = 0;
	while ((byte_read = read(fd, buf, 21)))
	{
		if (byte_read == -1)
			return (0);
		nbr_tetriminos++;
	}
	close(fd);
	return (nbr_tetriminos);
}

static char		*get_part_str(char const *str, int start, int end)
{
	char	*result;
	int		i;

	if (!(result = (char *)malloc(sizeof(char) * (end - start))))
		return (NULL);
	i = 0;
	while (start < end)
	{
		result[i] = str[start];
		start++;
		i++;
	}
	result[i] = 0;
	return (result);
}

static int		process_tetriminos(t_tetriminos *tetris, char *buf, int id)
{
	int		i;
	char	**tetriminos;
	char	*line;
	int		j;

	if (!(tetriminos = (char **)malloc(sizeof(char) * ((4 * 5) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (i <= 15)
	{
		if (!(line = get_part_str(buf, i, i + 5)))
			return (0);
		tetriminos[j] = line;
		i += 5;
		j++;
	}
	tetris->tetriminos = tetriminos;
	tetris->letter = id + 'A';
	return (1);
}

int				process_file(char *file, int i)
{
	t_tetriminos	*tetris;
	int				fd;
	int				nbr;
	int				byte_read;
	char			buf[21];

	if (!(nbr = get_nbr_tetriminos(file)))
		return (0);
	if (!(tetris = (t_tetriminos *)malloc(sizeof(t_tetriminos) * (nbr))))
		return (0);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	i = 0;
	while ((byte_read = read(fd, buf, 21)))
	{
		if (byte_read == -1 || !(process_tetriminos(&tetris[i], buf, i)))
			return (0);
		i++;
	}
	close(fd);
	i = -1;
	while (++i < nbr)
		if (!(shift_tetris(tetris[i].tetriminos)))
			return (0);
	return (1);
}

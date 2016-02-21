/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <framel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:49:39 by framel            #+#    #+#             */
/*   Updated: 2015/12/20 16:18:38 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int			*convert_buf(char *file, int const nb_line)
{
	int		i;
	int		*tab;
	char	*line;
	int		fd;

	if ((tab = ft_memalloc(sizeof(int) * (nb_line + 1))) == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		tab[i] = ft_atoi(line);
		i++;
	}
	close(fd);
	tab[i] = 0;
	return (&tab[0]);
}

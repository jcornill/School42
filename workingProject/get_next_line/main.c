/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:11:31 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/30 20:10:29 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/includes/libft.h"
#include <fcntl.h>

int		main(void)
{
	char	**buf;

	int fd = open("./file.txt", O_RDONLY);
	printf("%\n", get_next_line(fd, buf));
	close(fd);
}


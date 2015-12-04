/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:11:31 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/04 18:07:38 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	char	**buf;

	buf = NULL;
	int fd = open("./file.txt", O_RDONLY);
	printf("%d\n", get_next_line(fd, buf));
	close(fd);
}


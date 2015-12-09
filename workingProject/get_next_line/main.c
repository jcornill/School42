/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:11:31 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/08 19:00:49 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	char	*buf;

	buf = NULL;
	int fd = open("file.txt", O_RDONLY);
	int ret = 0;
	while ((ret = get_next_line(fd, &buf)))
		printf("%s\n", buf);
	//printf("%s\n", buf[0]);
//	printf("1:%d\n", get_next_line(fd, buf));
//	printf("%s\n", buf[0]);
//	printf("2:%d\n", get_next_line(fd, buf));
//	printf("%s\n", buf[0]);
//	printf("3:%d\n", get_next_line(fd, buf));
//	printf("%s\n", buf[0]);
//	printf("4:%d\n", get_next_line(fd, buf));
//	printf("%s\n", buf[0]);
//	printf("5:%d\n", get_next_line(fd, buf));
//	printf("%s\n", buf[0]);
	close(fd);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:11:06 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/10 19:52:58 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		get_next_line(int const fd, char **line);

#endif

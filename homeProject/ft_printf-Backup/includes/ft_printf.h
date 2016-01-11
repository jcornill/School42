/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:11:27 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/18 00:32:05 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
#  include <stdio.h>

int		ft_printf(char *str, ...);

int		ft_putwchar(wchar_t *str);
int		ft_putaddr(long nb);
int		ft_putnbr_base(long nb, int base, char a);
int		ft_putnbr_base_long(unsigned long nb, int base, char a);
int		ft_putnbr_long(long nb);
int		ft_putstrprintf(char *str);
int		ft_putnbrprintf(int n);
int		ft_putnbr_ulong(unsigned long n);
int		ft_putonewchar(wchar_t str);
int		ft_write_space(char *param, void *content, char c, int k);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:11:27 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/21 16:09:43 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int				ft_printf(char *str, ...);

int				ft_putwchar(wchar_t *str);
int				ft_putaddr(long nb);
int				ft_putnbr_base(long nb, int base, char a);
int				ft_putnbr_base_long(unsigned long nb, int base, char a);
int				ft_putnbr_long(long nb);
int				ft_putstrprintf(char *str);
int				ft_putnbrprintf(int n);
int				ft_putnbr_ulong(unsigned long n);
int				ft_putonewchar(wchar_t str);
int				ft_write_space(char *param, void *content, char c, int k);
int				get_content_len(void *content, char c);
int				print_arg_str(char *str, char param);
int				print_arg_nb(long nb, char c);
int				print_arg_unb(unsigned long nb, char c);
int				process_sharp(void *content, char c);
int				process_add(void *content, char c);
int				process_space(void *content, char c);
int				process_point(void *content, char c, char *param, int i);
int				ft_get_nbr_from_back(char *p, int i);
int				process_point_str(char *str, char *param, int i);
int				process_color(char *s);
int				p_arg(void *content, char *p, char c);
int				process_2(char c, void *content);
unsigned long	process_3(char c, char **str, void *content, long t[5]);
#endif

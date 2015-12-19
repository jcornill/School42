/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:17:52 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/19 17:09:46 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include "includes/ft_printf.h"

int main(void)
{
	wchar_t *test = NULL;
	int ret = 0;
	printf("size: %lu\n", sizeof(wchar_t));
	//printf("%d-%d-%d-%d\n", *test, *(test + 1), *(test +2), *(test + 3));
	ret += printf("%S\n", L"Ψ ψ");
	ret += printf("{%S}\n", test);
	ft_printf("%d\n", ret);
	ret = 0;
	ret += ft_printf("%S\n", L"Ψ ψ");
	ret += ft_printf("{%S}\n", test);
	ft_printf("\n%d\n", ret);
}

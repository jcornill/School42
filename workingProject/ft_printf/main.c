/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:33:07 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/17 20:29:25 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

int		main(int argc, char **argv)
{
	//wchar_t test2[7] = {195, 169, 196, 169, 197, 169};
	//wchar_t test2[5] = L"ïßoO";
	int		ret;

	ret = 0;
	fflush(stdout);
	if (!strcmp(argv[1], "simple"))
	{
		ret += ft_printf("This is a simple test.\n");
		ret += ft_printf("Another simple test.\nVery simple.\n");
		ret += ft_printf("");
		ret += ft_printf("\n");
		printf("\n Written char : %d Bad return (value);\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%s"))
	{
		ret += ft_printf("%s", "abc\n");
		ret += ft_printf("111%s333\n", "222");
		ret += ft_printf("%s333\n", "222");
		ret += ft_printf("111%s\n", "222");
		ret += ft_printf("{%s}\n", 0);
		ret += ft_printf("{%s}\n", "");
		ret += ft_printf("111%s333%s555\n", "222", "444");
		ret += ft_printf("111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
		ret += ft_printf("%s%s%s%s%s\n", "1", "2", "3", "4", "5");
		printf("\n Written char : %d Bad return (value);\n", ret);
		return (0);
	}
//*
	ret = 0;
	if (!strcmp(argv[1], "%d"))
	{
		ret += ft_printf("%d\n", 42);
		ret += ft_printf("%d\n", -42);
		ret += ft_printf("before %d after\n", 42);
		ret += ft_printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
		ret += ft_printf("a%db%dc%dd\n", 1, -2, 3);
		ret += ft_printf("%d\n", INT_MAX);
		ret += ft_printf("%d\n", INT_MIN);
		ret += ft_printf("\n");
		printf("\n Written char : %d Bad return (value);\n", ret);
		return (0);
	}
//*
	ret = 0;
	if (!strcmp(argv[1], "%%"))
	{
		ret += ft_printf("%%\n");
		ret += ft_printf("aa%%bb\n");
		ret += ft_printf("%%%%%%%%%%\n");
		ret += ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
		// ret += ft_printf("%\n");
		//	ret += ft_printf("{%}\n");
		//  ret += ft_printf("% Zoooo\n");
		//  ret += ft_printf("{% %}");
		printf("\n Written char : %d Bad return (value);\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%p"))
	{
		ret += ft_printf("%p\n", &strlcat);
		ret += ft_printf("%p\n", &strcmp);
		ret += ft_printf("%p\n", &printf);
		ret += ft_printf("%p\n", &strlen);
		ret += ft_printf("%p\n", 0);
		printf("\n Written char : %d Bad return (value);\n", ret);
		return (0);
	}
//*
	ret = 0;
	if (!strcmp(argv[1], "test multiple"))
	{
		ret += ft_printf("s: %s, p: %p, d:%d\n", "a string", &strlen, 42);
		ret += ft_printf("%s%p%d%d%p%s%p%p%s\n", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
		printf("\n Written char : %d Bad return (value);\n", ret);
		return (0);
	}
/*
//	ret += ft_printf("%S\n", L"米");
//	ret += ft_printf("%\n", L"我是一只猫。");
//	ret += ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
//	ret += ft_printf("a%Sb%sc%S", L"我", "42", L"猫");

ret += ft_printf("{%S}\n", NULL);
ret += ft_printf("%D\n", 0L);
ret += ft_printf("%D\n", 1L);
ret += ft_printf("%D\n", -1L);
ret += ft_printf("%D\n", 42L);
ret += ft_printf("%D\n", LONG_MAX);
ret += ft_printf("%D\n", LONG_MIN);
ret += ft_printf("Coucou les %D!\n", 42);

ret += ft_printf("%i\n", 42);
ret += ft_printf("%i\n", -42);
ret += ft_printf("Before %i after\n", 42);
ret += ft_printf("%i%i%i%i%i\n", 1, -2, 3, -4, 5);
ret += ft_printf("a%ib%ic%id\n", 1, -2, 3);

ret += ft_printf("%o\n", 42);
ret += ft_printf("before %o after\n", 42);
ret += ft_printf("%o%o%o%o%o\n", 1, 100, 999, 42, 999988888);
ret += ft_printf("a%ob%oc%od\n", 0, 55555, 100000);
ret += ft_printf("%o\n", -42);
ret += ft_printf("%o\n", ~0);
ret += ft_printf("%o\n", UINT_MAX);

ret += ft_printf("%O\n", 42);
ret += ft_printf("before %O after\n", 42);
ret += ft_printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888);
ret += ft_printf("a%Ob%Oc%Od\n", 0, 55555, 100000);
ret += ft_printf("%O\n", LONG_MAX);
ret += ft_printf("%O\n", -42);
ret += ft_printf("%O\n", ~0);

ret += ft_printf("%u\n", 42);
ret += ft_printf("before %u after\n", 42);
ret += ft_printf("%u%u%u%u%u\n", 1, 100, 999, 42, 999988888);
ret += ft_printf("a%ub%uc%ud\n", 0, 55555, 100000);
ret += ft_printf("%u\n", UINT_MAX);
ret += ft_printf("%u\n", -42);
ret += ft_printf("%u\n", ~0);

ret += ft_printf("%U\n", 42);
ret += ft_printf("before %U after\n", -42);
ret += ft_printf("%U\n", ULONG_MAX / 2);
ret += ft_printf("%U\n", ULONG_MAX);
ret += ft_printf("%U%U\n", -987, ~0);

ret += ft_printf("%x\n", 42);
ret += ft_printf("before %x after\n", 42);
ret += ft_printf("%x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
ret += ft_printf("a%xb%xc%xd\n", 0, 55555, 100000);
ret += ft_printf("%x, %x\n", 0, UINT_MAX);
ret += ft_printf("%x%x", -42, ~0);

ret += ft_printf("%X\n", 42);
ret += ft_printf("Before %X after\n", 42);
ret += ft_printf("%X%X%X%X%X\n", 1, 100, 999, 42, 999988888);
ret += ft_printf("a%Xb%Xc%Xd\n", 0, 55555, 100000);
ret += ft_printf("%X, %X\n", 0, UINT_MAX);
ret += ft_printf("%X%X\n", -42, ~0);
//	ret += ft_printf("%X\n", LONG_MAX);
//	ret += ft_printf("%X\n", ULONG_MAX);


int i;
ret += ft_printf("%p", &i);
printf("  :  %p\n", &i);
fflush(stdout);
unsigned long l;
ret += ft_printf("%p", &l);
printf("  :  %p\n", &l);
fflush(stdout);
char *str;
ret += ft_printf("%p", &str);
printf("  :  %p\n", &str);
fflush(stdout);
ret += ft_printf("%p", &strlen);
printf("  :  %p\n", &strlen);
fflush(stdout);
ret += ft_printf("%p", 0);
printf("  :  %p\n", 0);
fflush(stdout);
//*/
	printf("\n Written char : %d Bad return (value);\n", ret);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:33:07 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/19 17:11:12 by jcornill         ###   ########.fr       */
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
		ret += printf("This is a simple test.\n");
		ret += printf("Another simple test.\nVery simple.\n");
		ret += printf("");
		ret += printf("\n");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%s"))
	{
		ret += printf("%s", "abc\n");
		ret += printf("111%s333\n", "222");
		ret += printf("%s333\n", "222");
		ret += printf("111%s\n", "222");
		ret += printf("{%s}\n", 0);
		ret += printf("{%s}\n", "");
		ret += printf("111%s333%s555\n", "222", "444");
		ret += printf("111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
		ret += printf("%s%s%s%s%s\n", "1", "2", "3", "4", "5");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%d"))
	{
		ret += printf("%d\n", 42);
		ret += printf("%d\n", -42);
		ret += printf("before %d after\n", 42);
		ret += printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
		ret += printf("a%db%dc%dd\n", 1, -2, 3);
		ret += printf("%d\n", INT_MAX);
		ret += printf("%d\n", INT_MIN);
		ret += printf("\n");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%%"))
	{
		ret += printf("%%\n");
		ret += printf("aa%%bb\n");
		ret += printf("%%%%%%%%%%\n");
		ret += printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
		// ret += printf("%\n");
		//	ret += printf("{%}\n");
		//  ret += printf("% Zoooo\n");
		//  ret += printf("{% %}");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%p"))
	{
		ret += printf("%p\n", &strlcat);
		ret += printf("%p\n", &strcmp);
		ret += printf("%p\n", &printf);
		ret += printf("%p\n", &strlen);
		ret += printf("%p\n", 0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "multiple"))
	{
		ret += printf("s: %s, p: %p, d:%d\n", "a string", &strlen, 42);
		ret += printf("%s%p%d%d%p%s%p%p%s\n", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0 ;
	if (!strcmp(argv[1], "%S"))
	{
		ret += printf("{%S}\n", NULL);
		ret += printf("{%S}\n", L"Ã©");
		ret += printf("%S\n", L"米");
		ret += printf("%S\n", L"我是一只猫。");
		ret += printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
		ret += printf("%S%S%S\n", L"42", L"hahahaahahahah", L"Ψ ψ");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%D"))
	{	
		ret += printf("1. %D\n", 0L);
		ret += printf("2. %D\n", 1L);
		ret += printf("3. %D\n", -1L);
		ret += printf("4. %D\n", 42L);
		ret += printf("5. %D\n", LONG_MAX);
		ret += printf("6. %D\n", LONG_MIN);
		ret += printf("7. Coucou les %D!\n", 42);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%i"))
	{
		ret += printf("%i\n", 42);
		ret += printf("%i\n", -42);
		ret += printf("Before %i after\n", 42);
		ret += printf("%i%i%i%i%i\n", 1, -2, 3, -4, 5);
		ret += printf("a%ib%ic%id\n", 1, -2, 3);
		ret += printf("%i%i\n", INT_MAX, INT_MIN);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%o"))
	{
		ret += printf("%o\n", 42);
		ret += printf("before %o after\n", 42);
		ret += printf("%o%o%o%o%o\n", 1, 100, 999, 42, 999988888);
		ret += printf("a%ob%oc%od\n", 0, 55555, 100000);
		ret += printf("%o\n", -42);
		ret += printf("%o\n", ~0);
		ret += printf("%o\n", UINT_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%O"))
	{
		ret += printf("%O\n", 42);
		ret += printf("before %O after\n", 42);
		ret += printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888);
		ret += printf("a%Ob%Oc%Od\n", 0, 55555, 100000);
		ret += printf("%O\n", LONG_MAX);
		ret += printf("%O\n", -42);
		ret += printf("%O\n", ~0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%u"))
	{
		ret += printf("%u\n", 42);
		ret += printf("before %u after\n", 42);
		ret += printf("%u%u%u%u%u\n", 1, 100, 999, 42, 999988888);
		ret += printf("a%ub%uc%ud\n", 0, 55555, 100000);
		ret += printf("%u\n", UINT_MAX);
		ret += printf("%u\n", -42);
		ret += printf("%u\n", ~0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%U"))
	{
		ret += printf("%U\n", 42);
		ret += printf("before %U after\n", -42);
		ret += printf("%U\n", ULONG_MAX / 2);
		ret += printf("%U\n", ULONG_MAX);
		ret += printf("%U%U\n", -987, ~0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%x"))
	{
		ret += printf("%x\n", 42);
		ret += printf("before %x after\n", 42);
		ret += printf("%x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
		ret += printf("a%xb%xc%xd\n", 0, 55555, 100000);
		ret += printf("%x, %x\n", 0, UINT_MAX);
		ret += printf("%x%x", -42, ~0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%X"))
	{
		ret += printf("%X\n", 42);
		ret += printf("Before %X after\n", 42);
		ret += printf("%X%X%X%X%X\n", 1, 100, 999, 42, 999988888);
		ret += printf("a%Xb%Xc%Xd\n", 0, 55555, 100000);
		ret += printf("%X, %X\n", 0, UINT_MAX);
		ret += printf("%X%X\n", -42, ~0);
		ret += printf("%X\n", LONG_MAX);
		ret += printf("%X\n", ULONG_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%c"))
	{
		ret += printf("%c\n", 'c');
		ret += printf("%c %c\n", '4', '2');
		ret += printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
						 ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
						 '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
						 '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
						 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
						 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
						 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
						 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
		ret += printf("%c\n", 0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%C"))
	{
		ret += printf("1. %C\n", 'c');
		ret += printf("2. %C%C\n", '4', '2');
		ret += printf("3 .%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\n",
						 ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
						 '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
						 '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
						 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
						 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
						 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
						 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "multiple2"))
	{
		ret += printf("%s %d %p %x \n", "bonjour ", 42, &free, 42);
		ret += printf("%s%d%p%D%i%o%O%u%U%x%X%c\n","bonjour", 42, &strcmp, LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c');
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:33:07 by jcornill          #+#    #+#             */
/*   Updated: 2015/12/19 20:08:28 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

int		main(int argc, char **argv)
{
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
		ret += printf("%\n");
		ret += printf("{%}\n");
		ret += printf("% Zoooo\n");
		ret += printf("{% %}");
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
		ret += printf("4. %C\n", L'é');
		ret += printf("5. %C%C\n", L'Ã', L'©');
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "multiple2"))
	{
		ret += printf("1. %s %d %p %x %S %C\n", "bonjour ", 42, &free, 42, L"Bonjour", L'C');
		ret += printf("2. %s%S%d%p%D%i%o%O%u%U%x%X%c%C\n","bonjour", L"Ã©Ã©Ã©Ã©", 42, &strcmp, LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'Ã');
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%l%"))
	{
		ret += printf("1. %ld%ld\n", 0, 42);
		//ret += printf("2. %ld\n", (long)INT_MAX + 1);
		//ret += printf("3. %ld\n", (long)INT_MIN - 1);
		ret += printf("4. %ld\n", LONG_MAX);
		ret += printf("5. %ld\n", LONG_MIN);
		ret += printf("6. %li%li\n", 0, 42);
		//ret += printf("7. %li\n", (long)INT_MAX + 1);
		//ret += printf("8. %li\n", (long)INT_MIN - 1);
		ret += printf("9. %li\n", LONG_MAX);
		ret += printf("10. %li\n", LONG_MIN);
		//ret += printf("11. %lu, %lu\n", 0, ULONG_MAX);
		//ret += printf("12. %lo, %lo\n", 0, ULONG_MAX);
		//ret += printf("13. %lx, %lx\n", 0, ULONG_MAX);
		ret += printf("14. %lX, %lX\n", 0, ULONG_MAX);
		//ret += printf("%lc, %lc\n", L'暖', L'ح');
		//ret += printf("%ls, %ls\n", L"暖炉", L"Bonjour");
		ret += printf("15. %lO, %lO\n", 0, USHRT_MAX);
		ret += printf("16. %lU, %lU\n", 0, USHRT_MAX);
		ret += printf("17. %lD, %lD\n", 0, USHRT_MAX);
		ret += printf("18. %lp\n", 42);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%ll%"))
	{
		ret += printf("1. %lld%lld\n", 0, 42);
		ret += printf("2. %lld\n", LLONG_MAX);
		ret += printf("3. %lld\n", LLONG_MIN);
		ret += printf("4. %lli%lli\n", 0, 42);
		ret += printf("5. %lli\n", LLONG_MAX);
		ret += printf("6. %lli\n", LLONG_MIN);
		ret += printf("7. %llu, %llu\n", 0, ULLONG_MAX);
		ret += printf("8. %llo, %llo\n", 0, ULLONG_MAX);
		ret += printf("9. %llx, %llx\n", 0, ULLONG_MAX);
		ret += printf("10. %llX, %llX\n", 0, ULLONG_MAX);
		ret += printf("11. %llO, %llO\n", 0, USHRT_MAX);
		ret += printf("12. %llU, %llU\n", 0, USHRT_MAX);
		ret += printf("13. %llD, %llD\n", 0, USHRT_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%h%"))
	{
		ret += printf("1. %hd%hd\n", (short int)0, (short int)42);
		ret += printf("2. %hd\n", SHRT_MAX);
		ret += printf("3. %hd\n", SHRT_MIN);
		ret += printf("4. %hi%hi\n", 0, 42);
		ret += printf("5. %hi\n", SHRT_MAX);
		ret += printf("6. %hi\n", SHRT_MIN);
		ret += printf("7. %hu, %hu\n", 0, USHRT_MAX);
		ret += printf("8. %ho, %ho\n", 0, USHRT_MAX);
		ret += printf("9. %hx, %hx\n", 0, USHRT_MAX);
		ret += printf("10. %hX, %hX\n", 0, USHRT_MAX);
		ret += printf("11. %hO, %hO\n", 0, USHRT_MAX);
		ret += printf("12. %hU, %hU\n", 0, USHRT_MAX);
		ret += printf("13. %hD, %hD\n", 0, USHRT_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	ret = 0;
	if (!strcmp(argv[1], "%hh%"))
	{
		ret += printf("1. %hhd%hhd\n", 1, 42);
		ret += printf("2. %hhd\n", CHAR_MAX);
		ret += printf("3. %hhd\n", CHAR_MAX + 42);
		ret += printf("4. %hhd\n", CHAR_MIN);
		ret += printf("5. %hhd\n", CHAR_MIN - 42);
		ret += printf("6. %hhi%hhi\n", 0, 42);
		ret += printf("7. %hhd\n", CHAR_MAX);
		ret += printf("8. %hhd\n", CHAR_MAX + 42);
		ret += printf("9. %hhi\n", CHAR_MIN);
		ret += printf("10. %hhi\n", CHAR_MIN - 42);
		ret += printf("11. %hhu, %hhu\n", 0, UCHAR_MAX);
		ret += printf("12. %hho, %hho\n", 0, UCHAR_MAX);
		ret += printf("13. %hhx, %hhx\n", 0, UCHAR_MAX);
		ret += printf("14. %hhX, %hhX\n", 0, UCHAR_MAX);
		ret += printf("15. %hhu, %hhu\n", 0, UCHAR_MAX + 42);
		ret += printf("16. %hho, %hho\n", 0, UCHAR_MAX + 42);
		ret += printf("17. %hhx, %hhx\n", 0, UCHAR_MAX + 42);
		ret += printf("18. %hhX, %hhX\n", 0, UCHAR_MAX + 42);
		ret += printf("19. %hhO, %hhO\n", 0, USHRT_MAX);
		ret += printf("20. %hhU, %hhU\n", 0, USHRT_MAX);
		ret += printf("21. %hhD, %hhD\n", 0, USHRT_MAX);
		//ret += printf("22. %hhC, %hhC\n", 0, L'米');
		//ret += printf("23. %hhS, %hhS\n", 0, L"米米");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	if (!strcmp(argv[1], "%j%"))
	{
		ret += printf("%jd%jd\n", 0, 42);
		ret += printf("%jd\n", LLONG_MAX);
		ret += printf("%jd\n", LLONG_MIN);
		ret += printf("%ji%ji\n", 0, 42);
		ret += printf("%ji\n", LLONG_MAX);
		ret += printf("%ji\n", LLONG_MIN);
		ret += printf("%ju, %ju\n", 0, ULLONG_MAX);
		ret += printf("%jo, %jo\n", 0, ULLONG_MAX);
		ret += printf("%jx, %jx\n", 0, ULLONG_MAX);
		ret += printf("%jX, %jX\n", 0, ULLONG_MAX);
		ret += printf("%jO, %jO\n", 0, USHRT_MAX);
		ret += printf("%jU, %jU\n", 0, USHRT_MAX);
		ret += printf("%jD, %jD\n", 0, USHRT_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	if (!strcmp(argv[1], "%z%"))
	{
		ret += printf("1. %zd%zd\n", 0, 42);
		//ret += printf("2. %zd\n", LLONG_MAX);
		ret += printf("3. %zi%zi\n", 0, 42);
		//ret += printf("4. %zi\n", LLONG_MAX);
		ret += printf("5. %zu, %zu\n", 0, ULLONG_MAX);
		ret += printf("6. %zo, %zo\n", 0, ULLONG_MAX);
		ret += printf("7. %zx, %zx\n", 0, ULLONG_MAX);
		ret += printf("8, %zX, %zX\n", 0, ULLONG_MAX);
		ret += printf("9. %zO, %zO\n", 0, USHRT_MAX);
		ret += printf("10. %zU, %zU\n", 0, USHRT_MAX);
		ret += printf("11. %zD, %zD\n", 0, USHRT_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	if (!strcmp(argv[1], "%#%"))
	{
		ret += printf("1. %#o\n", 42);
		ret += printf("2. %#o\n", 0);
		ret += printf("3. %#o\n", INT_MAX);
		ret += printf("4. %#O\n", 1);
		ret += printf("5. %#x\n", 42);
		ret += printf("6. %#x\n", 0);
		ret += printf("7. %#x\n", INT_MAX);
		ret += printf("8. %#X\n", 42);
		ret += printf("9. %#X\n", 0);
		ret += printf("10. %#X\n", INT_MAX);
		//ret += printf("11. %#c\n", 0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	if (!strcmp(argv[1], "%+%"))
	{
		//ret += printf("1. %+d\n", 42);
		ret += printf("2. %+d\n", -42);
		ret += printf("3. %+i\n", 42);
		ret += printf("4. %+i\n", -42);
		//ret += printf("5. %+c", 0);
		//ret += printf("6. %+C", 0);
		ret += printf("7. %+o\n", 0);
		ret += printf("8. %+o\n", 42);
		ret += printf("9. %+O\n", 0);
		ret += printf("10. %+O\n", 42);
		//ret += printf("11. [%+s]\n", 0);
		ret += printf("12. [%+s]\n", "(null)");
		ret += printf("13. %+O\n", 1);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	if (!strcmp(argv[1], "ad1"))
	{
		ret += printf("1. {%10d}\n", 42);
		ret += printf("2. {%4d}\n", 10000);
		ret += printf("3. {%30d}\n", 10000);
		ret += printf("4. {%10d}\n", -42);
		//ret += printf("5. {%3c}\n", 0);
		ret += printf("6. {%5p}\n", 0);
		ret += printf("7. {%-15p}\n", 0);
		ret += printf("8. {%-13p}\n", &strlen);
		ret += printf("9. {%-12p}\n", &strlen);
		ret += printf("10. {%-10d}", 42);
		ret += printf("11. {%-4d}\n", 10000);
		ret += printf("12. {%-30d}\n", 10000);
		//ret += printf("{%30S}", L"我是一只猫。");
		//ret += printf("{%-30S}", L"我是一只猫。");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	if (!strcmp(argv[1], "ad2"))
	{
		ret += printf("1. {%010d}\n", 42);
		ret += printf("2. {%010d}\n", 0);
		ret += printf("3. {%04d}\n", 10000);
		ret += printf("4. {%030d}\n", 10000);
		ret += printf("5. {%030x}\n", 0xFFFF);
		ret += printf("6. {%030X}\n", 0xFFFF);
		//ret += printf("{%03c}", 0);
		ret += printf("7. {%05s}\n", "abc");
		//ret += printf("{%030S}", L"我是一只猫。");
		//ret += printf("8. {%05p}\n", 0);
		//ret += printf("9. {%015p}\n", &strcmp);
		//ret += printf("10. {%-15Z}\n", 123);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
}

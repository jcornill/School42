/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 22:33:07 by jcornill          #+#    #+#             */
/*   Updated: 2016/01/19 17:10:50 by jcornill         ###   ########.fr       */
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
//	long test1 = LONG_MAX;
//	long long test2 = LLONG_MAX;
//	printf("%ld,%lld\n",test1 ,test2);
	if (!strcmp(argv[1], "simple"))
	{
		ret += ft_printf("This is a simple test.\n");
		ret += ft_printf("Another simple test.\nVery simple.\n");
		ret += ft_printf("");
		ret += ft_printf("\n");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%s"))
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
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%d"))
	{
		ret += ft_printf("%d\n", 42);
		ret += ft_printf("%d\n", -42);
		ret += ft_printf("before %d after\n", 42);
		ret += ft_printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
		ret += ft_printf("a%db%dc%dd\n", 1, -2, 3);
		ret += ft_printf("%d\n", INT_MAX);
		ret += ft_printf("%d\n", INT_MIN);
		ret += ft_printf("\n");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%%"))
	{
		ret += ft_printf("%%\n");
		ret += ft_printf("aa%%bb\n");
		ret += ft_printf("%%%%%%%%%%\n");
		ret += ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
		ret += ft_printf("%\n");
		ret += ft_printf("{%}\n");
		ret += ft_printf("% Zoooo\n");
		ret += ft_printf("{% %}");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%p"))
	{
		ret += ft_printf("%p\n", &strlcat);
		ret += ft_printf("%p\n", &strcmp);
		ret += ft_printf("%p\n", &printf);
		ret += ft_printf("%p\n", &strlen);
		ret += ft_printf("%p\n", 0);
		printf("Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "multiple"))
	{
		ret += ft_printf("s: %s, p: %p, d:%d\n", "a string", &strlen, 42);
		ret += ft_printf("%s%p%d%d%p%s%p%p%s\n", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%S"))
	{
		ret += ft_printf("{%S}\n", NULL);
		ret += ft_printf("{%S}\n", L"Ã©");
		ret += ft_printf("%S\n", L"米");
		ret += ft_printf("%S\n", L"我是一只猫。");
		ret += ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\n", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
		ret += ft_printf("%S%S%S\n", L"42", L"hahahaahahahah", L"Ψ ψ");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%D"))
	{	
		ret += ft_printf("1. %D\n", 0L);
		ret += ft_printf("2. %D\n", 1L);
		ret += ft_printf("3. %D\n", -1L);
		ret += ft_printf("4. %D\n", 42L);
		ret += ft_printf("5. %D\n", LONG_MAX);
		ret += ft_printf("6. %D\n", LONG_MIN);
		ret += ft_printf("7. Coucou les %D!\n", 42);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%i"))
	{
		ret += ft_printf("%i\n", 42);
		ret += ft_printf("%i\n", -42);
		ret += ft_printf("Before %i after\n", 42);
		ret += ft_printf("%i%i%i%i%i\n", 1, -2, 3, -4, 5);
		ret += ft_printf("a%ib%ic%id\n", 1, -2, 3);
		ret += ft_printf("%i%i\n", INT_MAX, INT_MIN);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%o"))
	{
		ret += ft_printf("%o\n", 42);
		ret += ft_printf("before %o after\n", 42);
		ret += ft_printf("%o%o%o%o%o\n", 1, 100, 999, 42, 999988888);
		ret += ft_printf("a%ob%oc%od\n", 0, 55555, 100000);
		ret += ft_printf("%o\n", -42);
		ret += ft_printf("%o\n", ~0);
		ret += ft_printf("%o\n", UINT_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%O"))
	{
		ret += ft_printf("%O\n", 42);
		ret += ft_printf("before %O after\n", 42);
		ret += ft_printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888);
		ret += ft_printf("a%Ob%Oc%Od\n", 0, 55555, 100000);
		ret += ft_printf("%O\n", LONG_MAX);
		ret += ft_printf("%O\n", -42);
		ret += ft_printf("%O\n", ~0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%u"))
	{
		ret += ft_printf("%u\n", 42);
		ret += ft_printf("before %u after\n", 42);
		ret += ft_printf("%u%u%u%u%u\n", 1, 100, 999, 42, 999988888);
		ret += ft_printf("a%ub%uc%ud\n", 0, 55555, 100000);
		ret += ft_printf("%u\n", UINT_MAX);
		ret += ft_printf("%u\n", -42);
		ret += ft_printf("%u\n", ~0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%U"))
	{
		ret += ft_printf("%U\n", 42);
		ret += ft_printf("before %U after\n", -42);
		ret += ft_printf("%U\n", ULONG_MAX / 2);
		ret += ft_printf("%U\n", ULONG_MAX);
		ret += ft_printf("%U%U\n", -987, ~0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%x"))
	{
		ret += ft_printf("%x\n", 42);
		ret += ft_printf("before %x after\n", 42);
		ret += ft_printf("%x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
		ret += ft_printf("a%xb%xc%xd\n", 0, 55555, 100000);
		ret += ft_printf("%x, %x\n", 0, UINT_MAX);
		ret += ft_printf("%x%x", -42, ~0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%X"))
	{
		ret += ft_printf("%X\n", 42);
		ret += ft_printf("Before %X after\n", 42);
		ret += ft_printf("%X%X%X%X%X\n", 1, 100, 999, 42, 999988888);
		ret += ft_printf("a%Xb%Xc%Xd\n", 0, 55555, 100000);
		ret += ft_printf("%X, %X\n", 0, UINT_MAX);
		ret += ft_printf("%X%X\n", -42, ~0);
		ret += ft_printf("%X\n", LONG_MAX);
		ret += ft_printf("%X\n", ULONG_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%c"))
	{
		ret += ft_printf("%c\n", 'c');
		ret += ft_printf("%c %c\n", '4', '2');
		ret += ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
						 ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
						 '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
						 '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
						 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
						 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
						 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
						 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
		ret += ft_printf("%c\n", 0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%C"))
	{
		ret += ft_printf("1. %C\n", 'c');
		ret += ft_printf("2. %C%C\n", '4', '2');
		ret += ft_printf("3 .%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\n",
						 ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
						 '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
						 '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
						 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
						 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
						 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
						 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
		ret += ft_printf("4. %C\n", L'é');
		ret += ft_printf("5. %C%C\n", L'Ã', L'©');
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "multiple2"))
	{
		ret += ft_printf("1. %s %d %p %x %S %C\n", "bonjour ", 42, &free, 42, L"Bonjour", L'C');
		ret += ft_printf("2. %s%S%d%p%D%i%o%O%u%U%x%X%c%C\n","bonjour", L"Ã©Ã©Ã©Ã©", 42, &strcmp, LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'Ã');
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%l%"))
	{
		ret += ft_printf("1. %ld%ld\n", 0, 42);
		ret += ft_printf("2. %ld\n", (long)INT_MAX + 1);
		ret += ft_printf("3. %ld\n", (long)INT_MIN - 1);
		ret += ft_printf("4. %ld\n", LONG_MAX);
		ret += ft_printf("5. %ld\n", LONG_MIN);
		ret += ft_printf("6. %li%li\n", 0, 42);
		ret += ft_printf("7. %li\n", (long)INT_MAX + 1);
		ret += ft_printf("8. %li\n", (long)INT_MIN - 1);
		ret += ft_printf("9. %li\n", LONG_MAX);
		ret += ft_printf("10. %li\n", LONG_MIN);
		ret += ft_printf("11. %lu, %lu\n", 0, ULONG_MAX);
		ret += ft_printf("12. %lo, %lo\n", 0, ULONG_MAX);
		ret += ft_printf("13. %lx, %lx\n", 0, ULONG_MAX);
		ret += ft_printf("14. %lX, %lX\n", 0, ULONG_MAX);
		ret += ft_printf("15. %lO, %lO\n", 0, USHRT_MAX);
		ret += ft_printf("16. %lU, %lU\n", 0, USHRT_MAX);
		ret += ft_printf("17. %lD, %lD\n", 0, USHRT_MAX);
		ret += ft_printf("18. %lp\n", 42);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%ll%"))
	{
		ret += ft_printf("1. %lld%lld\n", 0, 42);
		ret += ft_printf("2. %lld\n", LLONG_MAX);
		ret += ft_printf("3. %lld\n", LLONG_MIN);
		ret += ft_printf("4. %lli%lli\n", 0, 42);
		ret += ft_printf("5. %lli\n", LLONG_MAX);
		ret += ft_printf("6. %lli\n", LLONG_MIN);
		ret += ft_printf("7. %llu, %llu\n", 0, ULLONG_MAX);
		ret += ft_printf("8. %llo, %llo\n", 0, ULLONG_MAX);
		ret += ft_printf("9. %llx, %llx\n", 0, ULLONG_MAX);
		ret += ft_printf("10. %llX, %llX\n", 0, ULLONG_MAX);
		ret += ft_printf("11. %llO, %llO\n", 0, USHRT_MAX);
		ret += ft_printf("12. %llU, %llU\n", 0, USHRT_MAX);
		ret += ft_printf("13. %llD, %llD\n", 0, USHRT_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%h%"))
	{
		ret += ft_printf("1. %hd%hd\n", (short int)0, (short int)42);
		ret += ft_printf("2. %hd\n", SHRT_MAX);
		ret += ft_printf("3. %hd\n", SHRT_MIN);
		ret += ft_printf("4. %hi%hi\n", 0, 42);
		ret += ft_printf("5. %hi\n", SHRT_MAX);
		ret += ft_printf("6. %hi\n", SHRT_MIN);
		ret += ft_printf("7. %hu, %hu\n", 0, USHRT_MAX);
		ret += ft_printf("8. %ho, %ho\n", 0, USHRT_MAX);
		ret += ft_printf("9. %hx, %hx\n", 0, USHRT_MAX);
		ret += ft_printf("10. %hX, %hX\n", 0, USHRT_MAX);
		ret += ft_printf("11. %hO, %hO\n", 0, USHRT_MAX);
		ret += ft_printf("12. %hU, %hU\n", 0, USHRT_MAX);
		ret += ft_printf("13. %hD, %hD\n", 0, USHRT_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%hh%"))
	{
		ret += ft_printf("1. %hhd%hhd\n", 1, 42);
		ret += ft_printf("2. %hhd\n", CHAR_MAX);
		ret += ft_printf("3. %hhd\n", CHAR_MAX + 42);
		ret += ft_printf("4. %hhd\n", CHAR_MIN);
		ret += ft_printf("5. %hhd\n", CHAR_MIN - 42);
		ret += ft_printf("6. %hhi%hhi\n", 0, 42);
		ret += ft_printf("7. %hhd\n", CHAR_MAX);
		ret += ft_printf("8. %hhd\n", CHAR_MAX + 42);
		ret += ft_printf("9. %hhi\n", CHAR_MIN);
		ret += ft_printf("10. %hhi\n", CHAR_MIN - 42);
		ret += ft_printf("11. %hhu, %hhu\n", 0, UCHAR_MAX);
		ret += ft_printf("12. %hho, %hho\n", 0, UCHAR_MAX);
		ret += ft_printf("13. %hhx, %hhx\n", 0, UCHAR_MAX);
		ret += ft_printf("14. %hhX, %hhX\n", 0, UCHAR_MAX);
		ret += ft_printf("15. %hhu, %hhu\n", 0, UCHAR_MAX + 42);
		ret += ft_printf("16. %hho, %hho\n", 0, UCHAR_MAX + 42);
		ret += ft_printf("17. %hhx, %hhx\n", 0, UCHAR_MAX + 42);
		ret += ft_printf("18. %hhX, %hhX\n", 0, UCHAR_MAX + 42);
		ret += ft_printf("19. %hhO, %hhO\n", 0, USHRT_MAX);
		ret += ft_printf("20. %hhU, %hhU\n", 0, USHRT_MAX);
		ret += ft_printf("21. %hhD, %hhD\n", 0, USHRT_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%j%"))
	{
		ret += ft_printf("%jd%jd\n", 0, 42);
		ret += ft_printf("%jd\n", LLONG_MAX);
		ret += ft_printf("%jd\n", LLONG_MIN);
		ret += ft_printf("%ji%ji\n", 0, 42);
		ret += ft_printf("%ji\n", LLONG_MAX);
		ret += ft_printf("%ji\n", LLONG_MIN);
		ret += ft_printf("%ju, %ju\n", 0, ULLONG_MAX);
		ret += ft_printf("%jo, %jo\n", 0, ULLONG_MAX);
		ret += ft_printf("%jx, %jx\n", 0, ULLONG_MAX);
		ret += ft_printf("%jX, %jX\n", 0, ULLONG_MAX);
		ret += ft_printf("%jO, %jO\n", 0, USHRT_MAX);
		ret += ft_printf("%jU, %jU\n", 0, USHRT_MAX);
		ret += ft_printf("%jD, %jD\n", 0, USHRT_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%z%"))
	{
		ret += ft_printf("1. %zd%zd\n", 0, 42);
		ret += ft_printf("2. %zd\n", LLONG_MAX);
		ret += ft_printf("3. %zi%zi\n", 0, 42);
		ret += ft_printf("4. %zi\n", LLONG_MAX);
		ret += ft_printf("5. %zu, %zu\n", 0, ULLONG_MAX);
		ret += ft_printf("6. %zo, %zo\n", 0, ULLONG_MAX);
		ret += ft_printf("7. %zx, %zx\n", 0, ULLONG_MAX);
		ret += ft_printf("8, %zX, %zX\n", 0, ULLONG_MAX);
		ret += ft_printf("9. %zO, %zO\n", 0, USHRT_MAX);
		ret += ft_printf("10. %zU, %zU\n", 0, USHRT_MAX);
		ret += ft_printf("11. %zD, %zD\n", 0, USHRT_MAX);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%#%"))
	{
		ret += ft_printf("1. %#o\n", 42);
		ret += ft_printf("2. %#o\n", 0);
		ret += ft_printf("3. %#o\n", INT_MAX);
		ret += ft_printf("4. %#O\n", 1);
		ret += ft_printf("5. %#x\n", 42);
		ret += ft_printf("6. %#x\n", 0);
		ret += ft_printf("7. %#x\n", INT_MAX);
		ret += ft_printf("8. %#X\n", 42);
		ret += ft_printf("9. %#X\n", 0);
		ret += ft_printf("10. %#X\n", INT_MAX);
		ret += ft_printf("11. %#c\n", 0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%+%"))
	{
		ret += ft_printf("1. %+d\n", 42);
		ret += ft_printf("2. %+d\n", -42);
		ret += ft_printf("3. %+i\n", 42);
		ret += ft_printf("4. %+i\n", -42);
		ret += ft_printf("5. %+o\n", 0);
		ret += ft_printf("6. %+o\n", 42);
		ret += ft_printf("7. %+O\n", 0);
		ret += ft_printf("8. %+O\n", 42);
		ret += ft_printf("9. [%+s]\n", "(null)");
		ret += ft_printf("10. %+O\n", 1);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "% %"))
	{
		ret += ft_printf("1. % d\n", 9999);
		ret += ft_printf("2. % d\n", -9999);
		ret += ft_printf("3. % i\n", 9999);
		ret += ft_printf("4. % i\n", -9999);
		ret += ft_printf("5. % u\n", 9999);
		ret += ft_printf("6. {% c}\n", 'a');
		ret += ft_printf("7. {% s}\n", NULL);
		ret += ft_printf("8. {% s}\n", "(null)");
		ret += ft_printf("9. {% s}\n", "");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "ad1"))
	{
		ret += ft_printf("1. {%10d}\n", 42);
		ret += ft_printf("2. {%4d}\n", 10000);
		ret += ft_printf("3. {%30d}\n", 10000);
		ret += ft_printf("4. {%5p}\n", 0);
		ret += ft_printf("5. {%-15p}\n", 0);
		ret += ft_printf("6. {%-13p}\n", &strlen);
		ret += ft_printf("7. {%-12p}\n", &strlen);
		ret += ft_printf("8. {%-10d}", 42);
		ret += ft_printf("9. {%-4d}\n", 10000);
		ret += ft_printf("10. {%-30d}\n", 10000);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "ad2"))
	{
		ret += ft_printf("1. {%010d}\n", 42);
		ret += ft_printf("2. {%010d}\n", 0);
		ret += ft_printf("3. {%04d}\n", 10000);
		ret += ft_printf("4. {%030d}\n", 10000);
		ret += ft_printf("5. {%030x}\n", 0xFFFF);
		ret += ft_printf("6. {%030X}\n", 0xFFFF);
		ret += ft_printf("7. {%05s}\n", "abc");
        ret += ft_printf("8. {% +d}\n", 42);
        ret += ft_printf("9. {%+ d}\n", 42);
        ret += ft_printf("10. {%+03d}\n", 123456);
        ret += ft_printf("11. %#O", 0);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%.1%"))
	{
		ret += ft_printf("1. %.4d\n", 42);
		ret += ft_printf("2. %.4d\n", 424242);
		ret += ft_printf("3. %.4d\n", -424242);
		ret += ft_printf("4. %15.4d\n", 42);
		ret += ft_printf("5. %15.4d\n", 424242);
		ret += ft_printf("6. %8.4d\n", 424242424);
		ret += ft_printf("7. %8.4d\n", -424242424);
		ret += ft_printf("8. %4.8d\n", 424242424);
		ret += ft_printf("9. %4.8d\n", -424242424);
		ret += ft_printf("10. %.4i\n", 42);
		ret += ft_printf("11. %15.4i\n", 42);
		ret += ft_printf("12. %.4u\n", 42);
		ret += ft_printf("13. %.4u\n", 424242);
		ret += ft_printf("14. %15.4u\n", 42);
		ret += ft_printf("15. %15.4u\n", 424242);
		ret += ft_printf("16. %8.4u\n", 424242424);
		ret += ft_printf("17. %4.8u\n", 424242424);
		ret += ft_printf("18. %8.14u\n", 424242424);
		ret += ft_printf("19. %4.18u\n", 424242424);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%.2%"))
	{
		ret += ft_printf("1. %.4o\n", 42);
		ret += ft_printf("2. %.4o\n", 424242);
		ret += ft_printf("3. %15.4o\n", 42);
		ret += ft_printf("4. %15.4o\n", 424242);
		ret += ft_printf("5. %8.4o\n", 424242424);
		ret += ft_printf("6. %4.15o\n", 42);
		ret += ft_printf("7. %4.15o\n", 424242);
		ret += ft_printf("8. %4.8o\n", 424242424);
		ret += ft_printf("9. %.4O\n", 42);
		ret += ft_printf("10. %15.4O\n", 42);
		ret += ft_printf("11. %4.15O\n", 42);
		ret += ft_printf("12. %.4x\n", 42);
		ret += ft_printf("13. %.4x\n", 424242);
		ret += ft_printf("14. %15.4x\n", 42);
		ret += ft_printf("15. %15.4x\n", 424242);
		ret += ft_printf("16. %8.4x\n", 424242424);
		ret += ft_printf("17. %4.15x\n", 42);
		ret += ft_printf("18. %4.15x\n", 42424242);
		ret += ft_printf("19. %4.8x\n", 424242424);
		ret += ft_printf("20. %.4X\n", 42);
		ret += ft_printf("21. %.4X\n", 424242);
		ret += ft_printf("22. %15.4X\n", 42);
		ret += ft_printf("23. %15.4X\n", 424242);
		ret += ft_printf("24. %8.4X\n", 424242424);
		ret += ft_printf("25. %4.15X\n", 42);
		ret += ft_printf("26. %4.15X\n", 424242);
		ret += ft_printf("27. %4.8X\n", 424242424);
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "%.3%"))
	{
		ret += ft_printf("1. %.4s\n", "42");
		ret += ft_printf("2. %15.4s\n", "42");
		ret += ft_printf("3. %4.15s\n", "42");
		ret += ft_printf("4. %4.15s\n", "I am 42");
		ret += ft_printf("5. %.c\n", 0);
		ret += ft_printf("6. %.5c\n", 0);
		ret += ft_printf("7. %.5c\n", 42);
		ret += ft_printf("8. %9.2p\n", 1234);
		ret += ft_printf("9. %9.2p\n", 1234567);
		ret += ft_printf("10. %.3%\n");
		printf("\n Written char : %d Bad return value\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "B%b"))
	{
		ret += ft_printf("1. {%b}\n", 0);
		ret += ft_printf("2. {%b}\n", 42);
		ret += ft_printf("3. {%b}\n", 123456);
		ret += ft_printf("4. %b\n", -42);
		printf("Written char : %d\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "Bcolor"))
	{
		ret += ft_printf("1. {red}%s{eof} julien de {lred}%d{eof}\n", "Bonjour", 42);
		ret += ft_printf("2. {Bonjour}\n");
		ret += ft_printf("3. {red}a{black}b{green}c{yellow}d{blue}e{purple}f{cyan}g{eof}h\n");
		printf("Written char : %d\n", ret);
		return (0);
	}
	else if (!strcmp(argv[1], "user"))
	{
		ret += ft_printf("Adding test here\n");
		ret += ft_printf("Bonjour %s !\n", "Julien");
		printf("Written char : %d\n", ret);
		return (0);
	}
}

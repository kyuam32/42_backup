#include <stdio.h>
#include <stdlib.h>

/*

char *ft_convert_base(char *nbr, char *base_from, char *base_to);
int is_valid(char *base, int len);
int get_length(char *str);

int main(int argc, char **argv)
{
	int t = argc;
	t++;

	char base_from[] = "0123456789";
//	char base_to[] = "01";
	char base_to[] = "0123456789abcdef";
	printf("from=%s\nto=%s\n", base_from, base_to);

	printf("%s\n%s\n", argv[1], ft_convert_base(argv[1], base_from, base_to));

//	char nbr[] = "      -+---++-2147483647";
	char nbr[] = "   -++--+2147483648";
	printf("%s\n%s\n--------\n", nbr, ft_convert_base(nbr, base_from, base_to));

	char nbr1[] = "      ++--+10";
	printf("%s\n%s\n--------\n", nbr1, ft_convert_base(nbr1, base_from, base_to));


	return 0;
}

*/


#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int		main(void)
{
	printf("=====CASE01=====\n");
	printf("nbr, base_from, base_to\n");
	printf("2147483647, ");
   	printf("0123456789, ");
   	printf("0123456789abcdef\n");
	printf("result : $%s$\n", ft_convert_base("2147483647", "0123456789", "0123456789abcdef"));
	printf("real answer : $7fffffff$\n");
	printf("=====CASE02=====\n");
	printf("nbr, base_from, base_to\n");
	printf("---------7fffffff, ");
   	printf("0123456789abcdef, ");
	printf("01\n");
	printf("result : $%s$\n", ft_convert_base("---------7fffffff", "0123456789abcdef", "01"));
	printf("real answer : $-1111111111111111111111111111111$\n");
	printf("=====CASE03=====\n");
	printf("nbr, base_from, base_to\n");
	printf("---+--0001023a, ");
	printf("0123456789, ");
	printf("0123456789\n");
	printf("result : $%s$\n", ft_convert_base("---+--0001023a", "0123456789", "0123456789"));
	printf("real answer : $-1023$\n");
	printf("=====CASE04=====\n");
	printf("nbr, base_from, base_to\n");
	printf("-0, ");
	printf("0123456789, ");
   	printf("abcdefghij\n");
	printf("result : $%s$\n", ft_convert_base("-0", "0123456789", "abcdefghij"));
	printf("real answer : $a$\n");
	printf("=====CASE05=====\n");
	printf("nbr, base_from, base_to\n");
	printf(" \t\t\t ---+++ff-f, ");
	printf("0123456789abcdef, ");
	printf("0123456789\n");
	printf("result : $%s$\n", ft_convert_base(" \t\t\t ---+++ff-f", "0123456789abcdef", "0123456789"));
	printf("real answer : $-255\n");
	printf("=====CASE06=====\n");
	printf("nbr, base_from, base_to\n");
	printf("aasdffeessddfffss, ");
	printf("asedf, ");
	printf("ss\n");
	printf("result : $%s$\n", ft_convert_base("aasdffeessddfffss", "asedf", "ss"));
	printf("real answer : $(null)$\n");
	printf("=====CASE07=====\n");
	printf("nbr, base_from, base_to\n");
	printf("-+-+- -+asdf, ");
   	printf("asdf");
	printf("fdsa\n");
	printf("result : $%s$\n", ft_convert_base("-+-+- -+asdf", "asdf", "fdsa"));
	printf("real answer : $f$\n");
	printf("=====CASE08=====\n");
	printf("nbr, base_from, base_to\n");
	printf("  -+-+- -+asdf, ");
	printf("ai sdf, ");
	printf("fdsa\n");
	printf("result : $%s$\n", ft_convert_base("  -+-+- -+asdf", "ai sdf", "fdsa"));
	printf("real answer : $(null)$\n");
	printf("=====CASE09=====\n");
	printf("nbr, base_from, base_to\n");
	printf("\t\t\t\t \v --++-asdf, ");
   	printf("asdf, ");
   	printf("fd-as\n");
	printf("result : $%s$\n", ft_convert_base("\t\t\t\t \v --++-asdf", "asdf", "fd-as"));
	printf("real answer : $(null)$\n");
	printf("=====CASE10=====\n");
	printf("nbr, base_from, base_to\n");
	printf("   -+a, ");
	printf("abcde, ");
	printf("\"\"\n");
	printf("result : $%s$\n", ft_convert_base("   -+a", "abcde", ""));
	printf("real answer : $(null)$\n");
	printf("=====CASE11=====\n");
	printf("nbr, base_from, base_to\n");
	printf(" -+a, ");
	printf("\"\", ");
   	printf("df");
	printf("result : $%s$\n", ft_convert_base(" -+a", "", "df"));
	printf("real answer : $(null)$\n");
}

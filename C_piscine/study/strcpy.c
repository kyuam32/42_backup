#include <stdio.h>

int ftstrcmp(char *str, const char *c);

int ft_atoi_base(const char *str, int str_base)
{
	char base[17];
	char *base_ptr;
	int i;
	int result;
	int n;

	base_ptr = base;
	base_ptr = "0123456789abcdef";
	i = 0;
	n = 1;
	result = 0;

	if (str[i] == '-')
	{
		n = -1;
	i++;		
	}
	while (str[i] != '\0')
	{
		result *= str_base;
		if (ftstrcmp(base, &str[i]))
			result += base[ftstrcmp(base, &str[i])];
		i++;
	}
	return (result * n);
}
int ftstrcmp(char *str, const char *c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == *c)
			return (i);
		i++;
	}
	return (0);
}

int main()
{
	const char *str = "1234";
	int str_base = 10;
	printf("%d\n",ft_atoi_base(str, str_base));
}

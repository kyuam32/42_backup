#include <unistd.h>
#include <stdio.h>

char *ft_strupcase(char *str)
{
	char *temp;
	int i;

	temp = str;
	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] >= 'a' && temp[i] <= 'z')
			temp[i] -= 32;
		i++;
	}
	return temp;
}

int main(void)
{
	char str[] = "ewdsa!@#DSADSAwq";
	printf("%s\n",ft_strupcase(str));
}

#include <unistd.h>
#include <stdio.h>


char *ft_strlowcase(char *str)
{
	char *temp;
	int i;

	temp = str;
	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] >= 'A' && temp[i] <= 'Z')
			temp[i] += 32;
		i++;
	}
	return temp;
}

int main(void)
{
	char str[] = "ewqASDW";
	printf("%s\n",ft_strlowcase(str));
}

#include <stdio.h>


char *ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return(s1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return(i);
}

int main()
{
	char s1[6];
	char s2[6] = "asdf";
	printf("%d",ft_strlen(s2));
}

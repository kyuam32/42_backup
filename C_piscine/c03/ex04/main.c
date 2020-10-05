#include <stdio.h>
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char *i;
	char *j;

	if (*str == 0)
		return (0);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = str;
			j = to_find;
			while (*i == *j)
			{
				i++;
				j++;
				if (*j == 0)
					return (str);
			}
		}
		str++;
	}
	return (0);
}

int main()
{
	char str[50] = "i got party tonight";
	char tof[20] = "party";
	char *s;
	char *t;

	s = str;
	t = tof;

	printf("%s\n",s);
	printf("%s\n",ft_strstr(str,tof));
}

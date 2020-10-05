#include <stdlib.h>
#include "stdio.h"

char    *ft_strdup(char *src)
{
	char *duple;
	int strlen;
	int i;

	i = 0;
	strlen = 0;
	while(src[strlen])
		strlen++;
	duple = (char *)malloc(sizeof(char) * (strlen + 1));
	while(i < strlen)
	{
		duple[i] = src[i];
		i++;
	}
	return(duple);
}

int main(void) {
	char *greet = "Salut";
	char *test1 = "Gonna pass this test, even if I gotta dup!\n";
	char *test2 = ft_strdup(test1);

	printf("%s\n", ft_strdup(greet));
	printf("test1: %s", test1);
	printf("test2: %s", test2);
	return 0;
}

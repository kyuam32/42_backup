#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int n;

	if (ac == 2)
	{
		n = atoi(av[1]);
		if((n & (n-1)))
			printf("%s\n","not power of 2");
		else
			printf("%s\n","power of 2");
		
		printf("%d",n);
	}
}

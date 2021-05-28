#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char duple[255];
	int i;

	if (ac == 3)
	{
		i = 0;
		while (i < 255)
		{
			duple[i] = 0;
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			if (!duple[av[2][i]])
				duple[av[2][i]] = 1;
			i++;
		}
		i = 0;
		while (av[1][i])
		{
			if (duple[av[1][i]] == 1)
			{
				write(1, &av[1][i], 1);
				duple[av[1][i]] = 2;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	char temp;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				temp = (av[1][i] + 13 - 'a') % 26 + 'a';
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				temp = (av[1][i] + 13 - 'A') % 26 + 'A';
			else
				temp = av[1][i];
			write(1, &temp, 1);
			i++;
		}
		write(1, "\n", 1);
	}
}

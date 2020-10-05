#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	char temp;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			temp = argv[1][i];
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				temp -= 'a' - 'A';
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				temp -= 'A' - 'a';
			write(1, &temp, 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}

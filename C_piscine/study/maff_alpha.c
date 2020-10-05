#include <unistd.h>

int main()
{
	char even;
	char odd;

	odd = 'a';
	even = 'B';
	while (even <= 'Z')
	{
		write(1, &odd, 1);
		write(1, &even, 1);
		odd += 2;
		even += 2;
	}
}

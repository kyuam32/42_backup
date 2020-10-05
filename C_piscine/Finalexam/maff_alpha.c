#include <unistd.h>

int main()
{
	char lower;
	char upper;

	lower = 'a';
	upper = 'B';
	while (lower <= 'z' && upper <= 'Z')
	{
		write(1, &lower, 1);
		write(1, &upper, 1);
		lower += 2;
		upper += 2;
	}
}

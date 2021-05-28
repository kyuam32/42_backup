#include <stdlib.h>
int     ft_printf(const char *format, ...);

int main()
{
	ft_printf("HELLO %d %s %c\n", 4902, "my name", 'h');
	system("leaks a.out");
	return (0);
}

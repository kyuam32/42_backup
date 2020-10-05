#include "ft_abs.h"
#include <stdio.h>

int	main(void)
{
	printf("%d, %d\n", 0, ABS(0));
	printf("%d, %d\n", 1, ABS(1));
	printf("%d, %d\n", -1, ABS(-1));
	printf("%d, %d\n", 10, ABS(10));
	printf("%d, %d\n", -10, ABS(-10));
	printf("%d, %d\n", 2147483647, ABS(2147483647));
	printf("%ld, %ld\n", -2147483648, ABS(-2147483648));
	return (0);
}

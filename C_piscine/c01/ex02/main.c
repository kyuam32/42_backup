#include <stdio.h>

void		ft_swap(int *a, int *b);

int		main()
{
	int a = 42;
	int b = 24;

	printf("%d\n",a);
	printf("%d\n",b);

	ft_swap(&a, &b);

	printf("%d\n",a);
	printf("%d\n",b);
}

void	ft_swap(int *a, int *b)
{
	int swapA;
	int swapB;

	swapA = *a;
	swapB = *b;

	*a = swapB;
	*b = swapA;
}

#include <stdlib.h>
#include <stdio.h>

int nb_len(int min, int max)
{
	int a;

	a = max - min;
	if (a > 0)
		return (a);
	return (-a);
}

int *ft_range(int min, int max)
{
	int *arr;
	int len;
	int i;

	if (min >= max)
		return (0);
	len = nb_len(min, max);
	i = 0;
	arr = (int *)malloc(sizeof(int) * len);
	while (min != max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}

int main()
{
	int min = -5;
	int max = 11;
	int i = 0;

	while ( i != nb_len(min, max))
	{
	printf("%d , ",ft_range(min, max)[i]);
	i++;
	}
}

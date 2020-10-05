#include <unistd.h>
#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}


int		main()
{
	int size;

	size = 10;

	int tab[size];
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	c = size;

	while (a < size)
	{
		tab[a] = c;
		printf("%d",tab[a]);
		printf("\n");
		a++;
		c--;
	}	

	ft_rev_int_tab(tab, size);
	printf("\n");

	while (b < size)
	{
		printf("%d",tab[b]);
		printf("\n");
		b++;
	}	
}

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_rev_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = size - 1;
	while (i < size / 2 )
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}


int		main()
{
	int size;

	size = 5;

	int tab[size]; 
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < 5)
	{
		tab[a] = a;
		printf("%d",tab[a]);
		printf("\n");
		a++;
	}	

	ft_rev_int_tab(tab, size);
	printf("\n");

	while (b < 5)
	{
		printf("%d",tab[b]);
		printf("\n");
		b++;
	}	



}

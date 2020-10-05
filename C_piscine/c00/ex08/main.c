#include <unistd.h>
#include <stdio.h>


void		print_nbr(int n, char *arr)
{
	char *temp;
	int index;

	temp = arr;
	while (*temp)
	{
		write(1, temp, 1);
		temp++;
	}
}

void		nbr_round(int n, char *arr)
{
	int index;
	char *temp;

	index = 0;
	temp = arr;

	while (index < n )
	{
		if (temp[index] >= temp[index + 1])
			temp[index + 1] = temp[index] + 1;
		index++;
	}

}

int			nbr_init_fin(int n, char *arr)
{	
	char *temp;
	int index;

	temp = arr;
	index = 0;
	while (index <	n)
	{
		arr[index] = '0';
		index++;
	}
	arr[index] = '\0';
}

void		ft_print_combn(int n)
{
	char arr[n];
	char init[n];
	char finish[n];
	int index;

	nbr_init(n, arr);
	nbr_round(n, arr);
	print_nbr(n, arr);

}

int			main(void)
{
	int n;

	n = 9;
	ft_print_combn(n);
}

#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b)
{
	int a_a;
	int b_b;
	
	a_a = *a;
	b_b = *b;

	*a = a_a / b_b;
	*b = a_a % b_b;
}


int main()
{
	int a = 42;
	int b = 10;

	printf("a = %d\n",a);
	printf("b = %d\n",b);

	ft_ultimate_div_mod(&a, &b);

	printf("a = %d\n",a);
	printf("b = %d\n",b);

}

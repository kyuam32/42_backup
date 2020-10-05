#include <stdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *temp;
	int swap;

	temp = lst
	while (lst->next != 0)
	{
		if(!cmp(lst->data,lst->next->data))
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;

		}
		lst = lst->next
	}
	lst = temp
	return(lst)
}

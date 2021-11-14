#include "push_swap.h"

t_arg	*radix_sort(t_arg *list_a, t_arg *list_b, int ranks)
{
	 int i;
	 int	size;
	 t_arg *head_list;

	 size = size_of_list(list_a);
	 i = 0;
	 while (i < 9)
	 {
		 ranks = 0;
		while (ranks < size)
		{
			head_list = list_a;
			if (((head_list->index >> i)&1) == 1)
			{
				list_a = rotate(list_a);
				write(1, "ra\n", 3);
			}
			else
			{
				push(&list_a, &list_b);
				write(1, "pb\n", 3);
			}
			++ranks;
		}
		while (size_of_list(list_b) > 0)
		{
			push(&list_b, &list_a);
			write(1, "pa\n", 3);
		}
		++i;
	 }
	 return (list_a);
}

int verif_list(t_arg *list, int ranks, int bit)
{
	 while (list)
	 {
			if (list->index >> ranks == bit)
		{
				return (0);
		}
			list = list->next;
	 }
	 return (1);
}

#include "push_swap.h"

t_arg   *five_numbers(t_arg *list_a, t_arg *list_b)
{
    int i;

    i = 0;
    if (size_of_list(list_a) == 5)
    {
        while (i < 2)
        {
            if (list_a->index < 2)
            {
                push(&list_a, &list_b);
                write(1, "pb\n", 3);
                ++i;
            }
            else
            {
                list_a = rotate(list_a);
                write(1, "ra\n", 3);
            }
        }
    }
    if (size_of_list(list_a) == 3)
        list_a = three_numbers(list_a);
    if (size_of_list(list_a) == 2 && list_a->index > list_a->next->index)
    {
        list_a = swap_stack(list_a);
	 	write(1, "sa\n", 3);
    }
    if (list_b->index < list_b->next->index)
    {
        list_b = swap_stack(list_b);
        write(1, "sb\n", 3);
    }
    while (size_of_list(list_b) > 0)
    {
        push(&list_b, &list_a);
        write(1, "pa\n", 3);
    }
    return (list_a);
}


t_arg *three_numbers(t_arg *list)
{
	if (list->index > list->next->next->index)
	{
		list = rotate(list);
		write(1, "ra\n", 3);
	}
	if (list->index > list->next->index)
	{
		list = swap_stack(list);
	 	write(1, "sa\n", 3);
	}
	if (list->index > list->next->next->index)
	{
		list = reverse_rotate(list);
		write(1, "rra\n", 4);
	}
	return (list);
}
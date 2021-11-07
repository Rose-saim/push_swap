#include "push_swap.h"

t_arg   *radick_sort(t_arg *list_a, t_arg *list_b, int ranks)
{
	int size_list;

	stack_a(&list_a, &list_b, ranks);
	size_list = size_of_list(list_a);
	if (size_list <= 3)
		ft_swap(&list_a);
	++ranks;
	while (size_of_list(list_b) > 0)
		stack_b(&list_b, &list_a, ranks);
   /* while (size_of_list(list_b) > 1 && ranks == 9)
	{
		if (list_b->index < list_b->next->index)
			list_b = rotate_a(list_b);
		push_a(&list_b, &list_a);
	}
	if (size_of_list(list_b) > 0)
		push_b(&list_b, &list_a);
		print_list(list_a);*/
	return (list_a);
}

void   ft_swap(t_arg **list)
{
	if ((*list)->next != NULL && (*list)->index > (*list)->next->index)
	{
		*list = swap_stack(*list);
		write(1, "sa\n", 3);
	}
	if (size_of_list(*list) > 2  && (*list)->next->index > (*list)->next->next->index )
	{
		*list = rotate(*list);
		write(1, "ra\n", 3);
	}
}

int rank_of_zero(t_arg *list, int ranks)
{
	t_arg   *cp_list;

	cp_list = list;
	while (list)
	{
		if (list->index_bit[ranks] == 1)
			return (ranks);
		list = list->next;
	}
	return (rank_of_zero(cp_list, ranks + 1));
}

int verif_list(t_arg *list, int ranks)
{
	while (list != NULL && list->next != NULL)
	{
		if (list->index_bit[ranks] == 0)
			return (0);
		list = list->next;
	}
	return (1);
}

int verif_list_b(t_arg *list, int ranks)
{
	while (list != NULL && list->next != NULL)
	{
		if (list->index_bit[ranks] == 1)
			return (0);
		list = list->next;
	}
	return (1);
}

void stack_a(t_arg **list_a, t_arg **list_b, int ranks)
{
	while (verif_list((*list_a), ranks) == 0)
	{
		if ((*list_a)->index_bit[ranks] == 1)
		{
			*list_a = rotate(*list_a);
			write(1, "ra\n", 3);
		}
		if ((*list_a)->index_bit[ranks] == 0)
		{
			push(list_a, list_b);
			write(1, "pb\n", 3);
		}
	}
}

void stack_b(t_arg **list_b, t_arg **list_a, int ranks)
{
	t_arg   *cp_list;

	cp_list = *list_b;
	while ((*list_a)->index - 1 != (*list_b)->index)
	{
			*list_b = rotate(*list_b);
			write(1, "rb\n", 3);
	}
	if ((*list_b)->index == (*list_a)->index - 1)
	{
		push(list_b, list_a);
		write(1, "pa\n", 3);
	}
}

/*
void stack_b(t_arg **list_b, t_arg **list_a, int ranks)
{
	int i;
	t_arg   *cp_list;

	i = 0;
	while (verif_list_b(*list_b, ranks) == 0 && i <= 3)
	{
		if ((*list_b)->index_bit[ranks] == 0)
			 *list_b = rotate_b(*list_b);
		if ((*list_b)->index < (*list_b)->next->index)
			 *list_b = rotate_b(*list_b);
		print_list(*list_b);
		if ((*list_b)->index_bit[ranks] == 1 || ranks == 9)
		{
			push_b(list_b, list_a);
			if ((*list_a)->index > (*list_a)->next->index)
				*list_a = swap_b(*list_a);
			++i;
		}
		puts("list_b====");
		print_list(*list_a);
		puts("list_a====");
	}
}
*/

t_arg *init(int num)
{
	t_arg *list_a;
	t_arg *cp_list_a;
	int		i = 5;
	int		o = 0;

	list_a = (t_arg *)malloc(sizeof(t_arg));
	list_a->argument = 5;
	cp_list_a = list_a;
	while (o < 5)
	{
		i *= -10.5;
		list_a->next = (t_arg *)malloc(sizeof(t_arg));
		list_a = list_a->next;
		list_a->argument += i;
		o++;
	}
	list_a = cp_list_a;
	return (list_a);
}

void	  print_list(t_arg *list)
{
		while (list)
		{
			printf("|%d|\n", list->argument);
			list = list->next;
		}
}

/*
int main()
{
	t_arg   *list_a;
	t_arg   *list_b;

	list_b = NULL;
	list_a = init(2);
	list_a = index_list(list_a, 5);
	list_a = translate_index_to_binary(list_a);
	radick_sort(list_a, list_b, 9);
	return 0;
}*/
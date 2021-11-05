#include "push_swap.h"

void   radick_sort(t_arg *list_a, t_arg *list_b, int ranks)
{
    while (ranks < 10)
    {

        stack_a(&list_a, &list_b, ranks);
    exit (0);
        puts("it's stack b");
        stack_b(list_a, list_b, ranks);
        puts("it's a while");
        ++ranks;
    }
    puts("no problem");
    return ;
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


void    test(t_arg *list)
{
    list->argument += 2;
}
void stack_a(t_arg **list_a, t_arg **list_b, int ranks)
{
    while (verif_list((*list_a), ranks) == 0)
    {
        if ((*list_a)->index_bit[ranks] == 1)
            (*list_a) = rotate_a((*list_a));
        if ((*list_a)->index_bit[ranks] == 0)
        {
            push_b(list_a, list_b);

        }
    }
}

void stack_b(t_arg *list_a, t_arg *list_b, int ranks)
{
    puts("LOL");
    while (verif_list(list_a, ranks) == 0)
    {
        if (list_a->index_bit[ranks] == 1)
          list_a = rotate_a(list_b);
        if (list_a->index_bit[ranks] == 0)
            push_b(list_b, list_a);
    }
}

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
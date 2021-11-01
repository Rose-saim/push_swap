#include "push_swap.h"

void    index_list(t_arg *list, int size)
{
    int         i;
    static int  array[size];

    list_to_array(list, array);
    quick_sort(array, size);
    i = 0;
    while (list)
    {
        array[i] = list->argument;
        i++;
        list = list->next;
    }
    return ;
}
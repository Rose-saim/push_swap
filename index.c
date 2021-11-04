#include "push_swap.h"

int size_of_list(t_arg *list)
{
    int size;

    size = 0;
    while (list)
    {
        ++size;
        list = list->next;
    }
    return (size);
}

t_arg    *index_list(t_arg *list, int size)
{
    int         i;
    t_array  array[size];

    list_to_array(list, array);
    i = 0;
    quick_sort(array, 0, size);
    while (i <= size)
    {
        array[i].index = i;
        i++;
    }
    list = index_search(list, array);
    i = 0;
    return (list);
}

void    list_to_array(t_arg *list, t_array array[])
{
    int i;

    i = 0;
    while (list)
    {
        array[i].argument = list->argument;
        list = list->next;
        i++;
    }
    return ;
}

t_arg   *index_search(t_arg *list, t_array array[])
{
    t_arg   *cp_list;
    int     i;

    cp_list = list; 
    i =0;
    while (i < 5)
    {
        printf("list %d|%d\n", array[i].index, array[i].argument);
        i++;
    }
    while (list)
    {
        i = 0;
        while (list->argument != array[i].argument)
            i++;
        if (list->argument == array[i].argument)
            list->index = array[i].index;
        list = list->next;
    }
    return (cp_list);
}

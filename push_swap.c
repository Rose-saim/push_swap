#include "push_swap.h"

t_arg	*push_swap(int argc, char **argv)
{
	t_arg	*list_argument_a;
	int		cp_list_argument_a;
	int		size;

	list_argument_a = list_number_of_argument(argv);
	size = size_of_list(list_argument_a);
	list_argument_a = index_list(list_argument_a, size);

	return(list_argument_a);
}

int main(int argc, char **argv)
{
	t_arg	*list;

	list = push_swap(argc, argv);
	while (list != NULL)
	{
		printf("ft|%d|%d\n", list->index, list->argument);
		list = list->next;
	}
}
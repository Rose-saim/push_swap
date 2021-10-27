#include "push_swap.h"

t_arg	*push_swap(int argc, char **argv)
{
	t_arg	*list_argument_a;
	t_arg	*list_argument_b;
	t_arg	*cp_list_argument;
	int		mediane;

	(void)argc;
	list_argument_a = list_number_of_argument(argv);
	list_argument_b = NULL;
	cp_list_argument = list_argument_a;
	mediane = ft_mediane(list_argument_a);
	printf("mediane|%d|\n", mediane);
	while (list_argument_a->index < numbers_argument(list_argument_a))
	{
		list_argument_a = index_list(list_argument_a);
		// printf("%d|%d\n", list_argument_a->index, list_argument_a->argument);
		if (list_argument_a->argument < mediane)
			push_b(&list_argument_a, &list_argument_b);
		else	
			list_argument_a = rotate_a(list_argument_a);
	}
		list_argument_a = index_list(list_argument_a);
	return(list_argument_a);
}

int main(int argc, char **argv)
{
	t_arg	*list;

	list = push_swap(argc, argv);
	while (list != NULL)
	{
		printf("ft%d|%d\n", list->index, list->argument);
		list = list->next;
	}
}
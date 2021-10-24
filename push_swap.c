#include "push_swap.h"

t_arg	*push_swap(int argc, char **argv)
{
	t_arg	*list_argument_a;
	t_arg	*list_argument_b;
	t_arg	*cp_list_argument;
	int		mediane;

	list_argument_a = list_number_of_argument(argv);
	list_argument_b = NULL;
	cp_list_argument = list_argument_a;
	mediane = ft_mediane(list_argument_a);
	printf("mediane|%d|\n", mediane);
	while (list_argument_a != NULL)
	{
		if (list_argument_a->argument < mediane)
			push_b(&list_argument_a, &list_argument_b);
		list_argument_a = list_argument_a->next;
	}
	while (list_argument_b != NULL)
	{
		printf("list_argument_b|%d|\n", list_argument_b->argument);
		list_argument_b = list_argument_b->next;
	}
	return(list_argument_a);
}

int main(int argc, char **argv)
{
	t_arg	*list;

	list = push_swap(argc, argv);
	while (list != NULL)
	{
		printf("%d\n", list->argument);
		list = list->next;
	}
}
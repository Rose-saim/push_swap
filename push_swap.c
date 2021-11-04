#include "push_swap.h"

t_arg	*push_swap(int argc, char **argv)
{
	t_arg	*list_a;
	t_arg	*list_b;
	int		size;
	int		cp_list_argument_a;

	list_b = NULL;
	list_a = list_number_of_argument(argv);
	size = size_of_list(list_a);
	list_a = index_list(list_a, size);
	puts("it's tanslate list");
	list_a = translate_index_to_binary(list_a);
	puts("it's radick sort");
	radick_sort(&list_a, &list_b, rank_of_zero(list_a, 0));
	return(list_a);
}

int main(int argc, char **argv)
{
	t_arg	*list;
	int	i =0;

	(void)argc;
	list = init(-5);
	list = push_swap(argc, argv);
	return 0;
}


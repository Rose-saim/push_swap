#include "push_swap.h"

t_arg	*push_swap(int argc, char **argv)
{
	t_arg	*list_a;
	t_arg	*list_b;
	int		cp_list_argument_a;

	puts("it's list number");
	list_a = list_number_of_argument(argv);
	puts("it's index list");
	list_a = index_list(list_a, 9);
	puts("it's tanslate list");
	list_a = translate_index_to_binary(list_a);
	puts("it's radick sort");
	radick_sort(list_a, list_b, 9);
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


#include "../push_swap.h"

char	*ft_checker(int argc, char **argv)
{
	t_arg	*list_argument;

	list_argument = list_number_of_argument(argv);
	if (!list_argument)
		return ("ERROR");

	// while (list_argument)
	// {
	// 	printf("%d\n", list_argument->argument);
	// 	list_argument = list_argument->next;
	// }
	if ("not sorted")
		// return ("KO");
	return ("OK");
}

int main(int argc, char **argv)
{
	printf("%s\n", ft_checker(argc, argv));
}
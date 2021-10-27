#include "push_swap.h"

int	total_number(t_arg *list)
{
	int	total_of_numbers;

	total_of_numbers = 0;
	while (list->next != NULL)
	{
		total_of_numbers += list->argument;
		list = list->next;
	}
	total_of_numbers += list->argument;
	return(total_of_numbers);
}

int	numbers_argument(t_arg *list)
{
	int	numbers_of_arguments;

	numbers_of_arguments = 0;
	while (list->next != NULL)
		list = list->next;
	numbers_of_arguments = list->index + 1;
	return (numbers_of_arguments);
}

int	ft_mediane(t_arg *list)
{
	int	mediane;
	
	mediane = total_number(list)/numbers_argument(list);
	return (mediane);
}
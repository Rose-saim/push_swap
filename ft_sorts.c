#include "push_swap.h"

int	ft_mediane(t_arg *list)
{
	int		total_of_numbers;
	int		mediane;

	total_of_numbers = 0;
	while (list->next != NULL)
	{
		total_of_numbers += list->argument;
		list = list->next;
	}
	total_of_numbers += list->argument;
	mediane = total_of_numbers/(list->index + 1);
	return (mediane);
}
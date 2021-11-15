/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:32:32 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/15 16:32:33 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arg	*little_numbers(t_arg *list_a, t_arg *list_b)
{
	int	i;

	i = 0;
	while (size_of_list(list_a) > 3)
	{
		if (list_a->index == i)
		{
			 push(&list_a, &list_b);
			 write(1, "pb\n", 3);
			 ++i;
		}
		else
		{
			 list_a = rotate(list_a);
			 write(1, "ra\n", 3);
		}
	}
	less_three(&list_a, &list_b);
	empty_list(&list_a, &list_b);
	return (list_a);
}

void	less_three(t_arg **list_a, t_arg **list_b)
{
	if (size_of_list(*list_a) == 3)
		*list_a = three_numbers(*list_a);
	if (size_of_list(*list_a) == 2 && (*list_a)->index > (*list_a)->next->index)
	{
		*list_a = swap_stack(*list_a);
		write(1, "sa\n", 3);
	}
	if (size_of_list(*list_b) > 1 && (*list_b)->index < (*list_b)->next->index)
	{
		*list_b = swap_stack(*list_b);
		write(1, "sb\n", 3);
	}
}

t_arg	*three_numbers(t_arg *list)
{
	while (list_sort(list) == 0)
	{
		if (list->index > list->next->next->index
			&& list->index > list->next->index)
		{
			list = rotate(list);
			write(1, "ra\n", 3);
		}
		if (list->index > list->next->index)
		{
			list = swap_stack(list);
			write(1, "sa\n", 3);
		}
		if (list->index > list->next->next->index)
		{
			list = reverse_rotate(list);
			write(1, "rra\n", 4);
		}
	}
	return (list);
}

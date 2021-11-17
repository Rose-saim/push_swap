/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:32:32 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/17 14:03:30 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arg	*little_numbers(t_arg *list_a, t_arg *list_b)
{
	t_arg	*end_list;

	while (size_of_list(list_a) > 3)
	{
		end_list = list_a;
		while (end_list->next->next)
			end_list = end_list->next;
		more_three(&list_a, &list_b, &end_list);
	}
	less_three(&list_a, &list_b);
	empty_list(&list_a, &list_b);
	return (list_a);
}

void	more_three(t_arg **list_a, t_arg **list_b, t_arg **end_list)
{
	static int		i = 0;

	if ((*list_a)->index == i)
	{
		push(list_a, list_b);
		write(1, "pb\n", 3);
		++i;
	}
	else if ((*end_list)->index == i || (*end_list)->next->index == i)
	{
		*list_a = reverse_rotate(*list_a);
		write(1, "rra\n", 4);
	}
	else
	{
		*list_a = rotate(*list_a);
		write(1, "ra\n", 3);
	}
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
	if (list->index < list->next->next->index
		&& list->index > list->next->index)
	{
		list = swap_stack(list);
		write(1, "sa\n", 3);
	}
	if (list->index < list->next->index
		&& list->next->index > list->next->next->index
		&& list->next->next->index > list->index)
	{
		list = swap_stack(list);
		write(1, "sa\n", 3);
		list = rotate(list);
		write(1, "ra\n", 3);
	}
	list = three_numbers_next(list);
	return (list);
}

t_arg	*three_numbers_next(t_arg *list)
{
	if (list->index > list->next->index
		&& list->next->index < list->next->next->index)
	{
		list = rotate(list);
		write(1, "ra\n", 3);
	}
	if (list->index > list->next->index
		&& list->next->index > list->next->next->index)
	{
		list = swap_stack(list);
		write(1, "sa\n", 3);
		list = reverse_rotate(list);
		write(1, "rra\n", 4);
	}
	if (list->index < list->next->index
		&& list->index > list->next->next->index)
	{
		list = reverse_rotate(list);
		write(1, "rra\n", 4);
	}
	return (list);
}

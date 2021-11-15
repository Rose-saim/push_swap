/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:22:42 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/15 17:22:43 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_sort(t_arg *list)
{
	while (list)
	{
		if (list->next && list->index > list->next->index)
			return (0);
		list = list->next;
	}
	return (1);
}

void	empty_list(t_arg **list_a, t_arg **list_b)
{
	while (size_of_list(*list_b) > 0)
	{
		push(list_b, list_a);
		write(1, "pa\n", 3);
	}
}

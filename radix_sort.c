/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:44:46 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/15 17:44:47 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arg	*radix_sort(t_arg *list_a, t_arg *list_b, int ranks)
{
	int	i;
	int	size;

	size = size_of_list(list_a);
	i = 0;
	while (i < 9)
	{
		ranks = 0;
		while (ranks < size)
		{
			action_radix(&list_a, &list_b, i);
			++ranks;
		}
		empty_list(&list_a, &list_b);
		++i;
	}
	return (list_a);
}

void	action_radix(t_arg **list_a, t_arg **list_b, int i)
{
	t_arg	*head_list;

	head_list = *list_a;
	if (((head_list->index >> i) & 1) == 1)
	{
		*list_a = rotate(*list_a);
		write(1, "ra\n", 3);
	}
	else
	{
		push(list_a, list_b);
		write(1, "pb\n", 3);
	}
}

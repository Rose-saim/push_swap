/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:14:48 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/17 12:10:35 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arg	*reverse_rotate(t_arg *list)
{
	t_arg	*node;
	t_arg	*head_list;

	head_list = list;
	while (list->next->next)
		list = list->next;
	node = list->next;
	list->next = NULL;
	node->next = head_list;
	return (node);
}

void	both_reverse_rotate(t_arg **list_a, t_arg **list_b)
{
	*list_a = reverse_rotate(*list_a);
	*list_b = reverse_rotate(*list_b);
	return ;
}

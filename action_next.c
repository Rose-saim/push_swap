/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:14:48 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/15 16:14:49 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arg	*reverse_rotate(t_arg *list)
{
	t_arg	*node;
	t_arg	*sv_list;

	node = (t_arg *)malloc(sizeof(t_arg));
	if (!node)
		return (0);
	sv_list = list;
	while (list->next->next != NULL)
		list = list->next;
	node->argument = list->next->argument;
	list->next = NULL;
	list = sv_list;
	list = node;
	list->next = sv_list;
	return (list);
}

void	both_reverse_rotate(t_arg **list_a, t_arg **list_b)
{
	*list_a = reverse_rotate(*list_a);
	*list_b = reverse_rotate(*list_b);
	return ;
}

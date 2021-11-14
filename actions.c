#include "push_swap.h"

t_arg	*swap_stack(t_arg *list)
{
	t_arg	*node;

	node = list->next;
	list->next = list->next->next;
	node->next = list;
	return (node);
}

void swap_both(t_arg **list_a, t_arg **list_b)
{
	*list_a = swap_stack(*list_a);
	*list_b = swap_stack(*list_b);
	return ;
}

void	push(t_arg **list_a, t_arg **list_b)
{
	t_arg	*node;

	node = *list_a;
	*list_a = (*list_a)->next;
	node->next = (*list_b);
	(*list_b) = node;
	return ;
}

t_arg	*rotate(t_arg *list)
{	
	t_arg	*node;
	t_arg	*sv_list;

	sv_list = list->next;
	node	= list;
	while (list->next)
		list = list->next;
	list->next = node;
	list = list->next;
	list->next = NULL;
	return (sv_list);
}

void	both_rotate(t_arg **list_a, t_arg **list_b)
{
	t_arg *sv_list_a;
	t_arg *sv_list_b;

	sv_list_a = rotate(*list_a);
	sv_list_b = rotate(*list_b);
	*list_a = sv_list_a;
	*list_b = sv_list_b;
	return ;
}

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

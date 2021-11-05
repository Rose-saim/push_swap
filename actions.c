#include "push_swap.h"

t_arg	*swap_a(t_arg *list)
{
	t_arg	*cp_list;

	cp_list = list;
	if (!cp_list)
		return (NULL);
	if (list->next == NULL)
		return (list);
	cp_list  = cp_list->next;
	list->next = cp_list->next;
	cp_list->next = list;
	return (cp_list);
}

t_arg	*swap_b(t_arg *list)
{
	t_arg	*cp_list;

	cp_list = list;
	if (!cp_list)
		return (NULL);
	if (list->next == NULL)
		return (list);
	cp_list  = cp_list->next;
	list->next = cp_list->next;
	cp_list->next = list;
	return (cp_list);
}

void swap_both(t_arg **list_a, t_arg **list_b)
{
	*list_a = swap_a(*list_a);
	*list_b = swap_b(*list_b);
	return ;
}

void	push_a(t_arg **list_a, t_arg **list_b)
{
	t_arg	*sv_list_a;
	t_arg	*sv_list_b;

	sv_list_a = *list_a;
	if (*list_b != NULL)
		sv_list_b = (*list_b)->next;
	(*list_b)->next = NULL;
	*list_a = *list_b;
	(*list_a)->next = sv_list_a;
	*list_b = sv_list_b;
	return ;
}

void	push_b(t_arg **list_a, t_arg **list_b)
{
	t_arg	*node;

	node = *list_a;
	*list_a = (*list_a)->next;
	node->next = (*list_b);
	(*list_b) = node;
	return ;
}

t_arg	*rotate_a(t_arg *list)
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

t_arg	*rotate_b(t_arg *list)
{
	t_arg	*node;

	node = malloc(sizeof(t_arg));
	if (!node)
		return (NULL);
	node = list->next;
	while (node->next != NULL)
		node = node->next;
	node = node->next;
	node->next->next = NULL;
	return (node);
}

void	both_rotate(t_arg **list_a, t_arg **list_b)
{
	t_arg *sv_list_a;
	t_arg *sv_list_b;

	sv_list_a = rotate_a(*list_a);
	sv_list_b = rotate_b(*list_b);
	*list_a = sv_list_a;
	*list_b = sv_list_b;
	return ;
}

t_arg	*reverse_rotate_a(t_arg *list)
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

t_arg	*reverse_rotate_b(t_arg *list)
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
	*list_a = reverse_rotate_a(*list_a);
	*list_b = reverse_rotate_b(*list_b);
	return ;
}

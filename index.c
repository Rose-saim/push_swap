/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:11:54 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/15 17:21:49 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_list(t_arg *list)
{
	int	size;

	size = 0;
	while (list)
	{
		++size;
		list = list->next;
	}
	return (size);
}

t_arg	*index_list(t_arg *list, int size)
{
	int		i;
	t_array	*array;

	i = 0;
	array = malloc(sizeof(t_array) * (size + 1));
	if (!array)
		return (NULL);
	list_to_array(list, array);
	quick_sort(array, 0, size - 1);
	while (i < size)
	{
		array[i].index = i;
		++i;
	}
	list = index_search(list, array);
	free(array);
	return (list);
}

void	list_to_array(t_arg *list, t_array array[])
{
	int	i;

	i = 0;
	while (list)
	{
		array[i].argument = list->argument;
		list = list->next;
		i++;
	}
	return ;
}

t_arg	*index_search(t_arg *list, t_array array[])
{
	t_arg	*cp_list;
	int		i;

	cp_list = list;
	while (list)
	{
		i = 0;
		while (list->argument != array[i].argument)
			i++;
		if (list->argument == array[i].argument)
			list->index = array[i].index;
		list = list->next;
	}
	return (cp_list);
}

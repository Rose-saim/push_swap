/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:17:16 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/15 16:17:17 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(t_arg *list)
{
	t_arg	*head_list;
	t_arg	*cp_list;

	head_list = list;
	cp_list = list;
	if (list == NULL)
		return (0);
	while (cp_list)
	{
		list = cp_list->next;
		while (list)
		{
			if (cp_list->argument == list->argument)
				return (0);
			list = list->next;
		}
		cp_list = cp_list->next;
	}
	return (1);
}

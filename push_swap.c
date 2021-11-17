/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:25:58 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/17 14:07:23 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_arg	*list_a;
	t_arg	*list_b;
	int		size;

	if (argc <= 1)
		exit(0);
	list_b = NULL;
	list_a = NULL;
	list_a = list_number_of_argument(argv);
	size = size_of_list(list_a);
	list_a = index_list(list_a, size);
	ft_error(list_a);
	if (size == 1 || list_sort(list_a) == 1)
	{
		free_lst(list_a);
		return (0);
	}
	if (size <= 5)
		list_a = little_numbers(list_a, list_b);
	else
		list_a = radix_sort(list_a, list_b, 0);
	free_lst(list_a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:06:08 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/11 20:36:59 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_arg	*list_a;
	t_arg	*list_b;
	int		size;

	(void)argc;
	list_b = NULL;
	list_a = list_number_of_argument(argv);
	size = size_of_list(list_a);
	list_a = index_list(list_a, size);
	if (size == 1 || list_sort(list_a) == 1)
		return ;
	if (size == 2 && list_sort(list_a) == 0)
	{
		list_a = swap_stack(list_a);
		write(1, "sa\n", 3);
	}
	else if (size == 3 && list_sort(list_a) == 0)
		list_a = three_numbers(list_a);
	else if (size <= 5)
		list_a = five_numbers(list_a, list_b);
	else
		list_a = radix_sort(list_a, list_b, 0);
	free_lst(list_a);
	return ;
}

int	main(int argc, char **argv)
{
	(void)argc;
	push_swap(argc, argv);
	return (0);
}

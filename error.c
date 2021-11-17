/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:17:16 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/17 13:00:32 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_arg *list)
{
	t_arg	*head_list;
	t_arg	*cp_list;

	head_list = list;
	cp_list = list;
	if (list == NULL)
		return ;
	while (cp_list)
	{
		list = cp_list->next;
		while (list)
		{
			if (cp_list->argument == list->argument)
			{
				free_lst(list);
				write(2, "Error\n", 6);
				exit(0);
			}
			list = list->next;
		}
		cp_list = cp_list->next;
	}
}

void	error_argument(char **argv, int argument, int verif, t_arg *list)
{
	while (argv[argument][verif])
	{
		if (!(argv[argument][verif] >= '0' && argv[argument][verif] <= '9')
			&& (argv[argument][verif] != '-' && argv[argument][verif] != ' '
			&& argv[argument][verif] != '+'))
		{	
			free_lst(list);
			write_error();
		}
		++verif;
	}
}

void	lst_error(char *number)
{
	int	o;

	o = 0;
	while (number[o])
	{
		if (!(number[o] >= '0' && number[o] <= '9')
			&& number[o] != '+' && number[o] != '-')
			write_error();
		o++;
	}
}

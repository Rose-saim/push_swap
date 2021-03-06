/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:15:04 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/17 13:21:06 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arg	*list_number_of_argument(char **argv)
{
	t_arg	*list_argument;
	int		size;
	int		verif;
	int		argument;

	argument = 1;
	verif = 0;
	list_argument = NULL;
	while (argv[argument])
	{
		size = 0;
		while (argv[argument][verif] == ' ')
			++verif;
		if (argv[argument][verif] == '\0')
			error_free(list_argument);
		if (argv[argument][0] == '\0')
			error_free(list_argument);
		list_argument = copy_list(argv, argument, 0, list_argument);
		argument++;
	}
	return (list_argument);
}

t_arg	*copy_list(char **argv, int argument, int size, t_arg *list_argument)
{
	int		number_node;
	char	*number;
	int		verif;
	int		i;
	int		o;

	verif = 0;
	o = 0;
	i = 0;
	while (argv[argument][i] != '\0')
	{
		error_argument(argv, argument, verif, list_argument);
		i += size;
		while (argv[argument][i] == ' ')
			i++;
		if (argv[argument][i] == '\0')
			break ;
		size = strclen(argv[argument] + i, ' ');
		number = copy(argv[argument] + i, size);
		lst_error(number);
		number_node = ft_atoi(number, list_argument);
		list_argument = add_back_li(list_argument, number_node);
	}
	return (list_argument);
}

t_arg	*add_back_li(t_arg *list, int number)
{
	t_arg	*cp_list;
	t_arg	*node;

	cp_list = list;
	node = (t_arg *)malloc(sizeof(t_arg));
	if (!node)
		return (NULL);
	node->argument = number;
	node->next = NULL;
	if (list == NULL)
		return (node);
	else
	{
		while (list->next)
			list = list->next;
		list->next = node;
	}
	return (cp_list);
}

void	free_lst(t_arg *list)
{
	t_arg	*to_delete;

	while (list)
	{
		to_delete = list;
		list = list->next;
		free(to_delete);
	}
	return ;
}

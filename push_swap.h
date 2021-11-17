/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:20:08 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/17 13:16:57 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_array
{
	int	argument;
	int	index;
}				t_array;

typedef struct s_arg
{
	int				argument;
	int				index;
	struct s_arg	*next;
}				t_arg;

t_arg	*reverse_rotate(t_arg *list);
t_arg	*rotate(t_arg *list);
t_arg	*swap_stack(t_arg *list);
void	both_rotate(t_arg **list_a, t_arg **list_b);
void	both_reverse_rotate(t_arg **list_a, t_arg **list_b);
void	push(t_arg **list_a, t_arg **list_b);
void	swap_both(t_arg **list_a, t_arg **list_b);

char	*copy(char *str_arg, int size);
int		strclen(char *str, int c);

int		ft_atoi(char *str, t_arg *list);

t_arg	*copy_list(char **argv, int argument, int size, t_arg *list_argument);
t_arg	*list_number_of_argument(char **argv);

t_arg	*add_back_li(t_arg *list, int number);
void	empty_list(t_arg **list_a, t_arg **list_b);
void	free_lst(t_arg *list);
int		list_sort(t_arg *list_a);
int		size_of_list(t_arg *list);

void	list_to_array(t_arg *list, t_array array[]);
t_arg	*index_list(t_arg *list, int size);
t_arg	*index_search(t_arg *list, t_array array[]);

void	quick_sort(t_array tab[], int first, int last);
void	swap(int *a, int *b);

t_arg	*radix_sort(t_arg *list_a, t_arg *list_b, int ranks);
void	action_radix(t_arg **list_a, t_arg **list_b, int i);
int		no_bit(t_arg *list, int i);

void	less_three(t_arg **list_a, t_arg **list_b);
void	more_three(t_arg **list_a, t_arg **list_b, t_arg **end_list);
t_arg	*little_numbers(t_arg *list_a, t_arg *list_b);
t_arg	*three_numbers(t_arg *list);
t_arg	*three_numbers_next(t_arg *list);

void	error_free(t_arg *list);
void	error_argument(char **argv, int argmument, int verif, t_arg *list);
void	ft_error(t_arg *list);
void	lst_error(char *number);
void	write_error(void);

#endif

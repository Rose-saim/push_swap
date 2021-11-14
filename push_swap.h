#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_array
{
	int	argument;
	int	index;
}				t_array;

typedef	struct	s_arg
{
	int				argument;
	int				index;
	struct s_arg	*prev;
	struct s_arg	*next;
}				t_arg;

typedef	struct	db_list_repere
{
	int		size;
	t_arg	*first;
	t_arg	*last;
}				db_list;

char	*copy(char *str_arg, int size);
int		strclen(char *str, int c);

t_arg	*add_back_li(t_arg *list,int number);
t_arg	*list_number_of_argument(char **argv);
int		size_of_list(t_arg *list);
int		list_sort(t_arg *list_a);
void	free_lst(t_arg *list);

int		ft_atoi(char *str);

t_arg   *index_list(t_arg *list, int size);
t_arg   *index_search(t_arg *list, t_array array[]);

void	list_to_array(t_arg *list, t_array array[]);
void 	quick_sort(t_array tab[], int first, int last);
void 	swap(int *a, int *b);

t_arg	*reverse_rotate(t_arg *list);
t_arg	*rotate(t_arg *list);
t_arg	*swap_stack(t_arg *list);
void	both_rotate(t_arg **list_a, t_arg **list_b);
void	both_reverse_rotate(t_arg **list_a, t_arg **list_b);
void	push(t_arg **list_a, t_arg **list_b);
void	swap_both(t_arg **list_a, t_arg **list_b);

t_arg   *radix_sort(t_arg *list_a, t_arg *list_b, int ranks);

t_arg 	*three_numbers(t_arg *list);
t_arg   *five_numbers(t_arg *list_a, t_arg *list_b);

void	push_swap(int argc, char **argv);

void	  print_list(t_arg *list);
t_arg *init(int num);

#endif

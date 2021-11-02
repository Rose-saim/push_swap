#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_array
{
	int	argument;
	int	index;
}				t_array;

typedef	struct	s_arg
{
	int				argument;
	int				index;
	struct s_arg	*next;
}				t_arg;

char	*ft_checker(int argc, char *argv[]);
char	*copy(char *str_arg, int size);

int		ft_error(char **argv, int size);
int		ft_atoi(char *str);

t_arg	*add_back_li(t_arg *list, int number);
t_arg	*add_front_li(t_arg *list, int number);
t_arg    *index_list(t_arg *list, int size);
t_arg   *index_search(t_arg *list, t_array array[]);
t_arg	*list_number_of_argument(char **argv);
t_arg	*reverse_rotate_a(t_arg *list);
t_arg	*reverse_rotate_b(t_arg *list);
t_arg	*rotate_a(t_arg *list);
t_arg	*rotate_b(t_arg *list);
t_arg	*swap_a(t_arg *list);
t_arg	*swap_b(t_arg *list);

void	both_reverse_rotate(t_arg **list_a, t_arg **list_b);
void    list_to_array(t_arg *list, t_array array[]);
void 	swap(int *a, int *b);
void	swap_both(t_arg **list_a, t_arg **list_b);
void 	quick_sort(t_array tab[], int first, int last);
void	push_a(t_arg **list_a, t_arg **list_b);
void	push_b(t_arg **list_a, t_arg **list_b);
void	both_rotate(t_arg **list_a, t_arg **list_b);

t_arg *init(int num);

#endif

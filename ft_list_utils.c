#include "push_swap.h"


t_arg	*list_number_of_argument(char **argv)
{
	char	*number;
	int		number_node;
	int		size;
	int		i;
	int		o;
	int		argument;
	t_arg	*list_argument;

	argument = 1;
	list_argument = NULL;
	while (argv[argument])
	{
		o = 0;
		i = 0;
		size = 0;
		while (argv[argument][i] != '\0')
		{
			i += size;
			while (argv[argument][i] == ' ')
				i++;
			if (argv[argument][i] == '\0')
				break;
			size = strclen(argv[argument] + i, ' ');
			number = copy(argv[argument] + i, size);
			while (number[o])
			{
				if (!(number[o] >= '0' && number[o] <= '9') && number[o] != '+' && number[o] != '-')
					return (NULL);
				o++;
			}
			number_node = ft_atoi(number);
			list_argument = add_back_li(list_argument, number_node);
		}
		argument++;
	}
	return (list_argument);
}

t_arg	*add_back_li(t_arg *list, int number)
{
	t_arg	*cp_list;
	t_arg	*node;

	cp_list = list;
	node = (t_arg *)malloc(sizeof(t_arg));
	if (node)
	{
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
	}
	return (cp_list);
}

void	free_lst(t_arg *list)
{
	t_arg *to_delete;

	while (list)
	{
		to_delete = list;
		list = list->next;
		free(to_delete);
	}
	return ;
}

int	list_sort(t_arg *list)
{
	while (list)
	{
		if (list->next && list->index > list->next->index)
			return (0);
		list = list->next;
	}
	return (1);
}
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
			if (!list_argument)
				list_argument = add_front_li(list_argument, number_node);
			else
				list_argument = add_back_li(list_argument, number_node);
		}
		argument++;
	}
	return (list_argument);
}
t_arg	*add_front_li(t_arg *list, int number)
{
	t_arg	*sv_list;
	t_arg	*node;

	sv_list = list;
	node = (t_arg *)malloc(sizeof(t_arg));
	if (!node)
		return (NULL);
	node->argument = number;
	list = node;
	list->next = sv_list;
	return (list);
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
	while (list->next != NULL)
		list = list->next;
	list->next = node;
	list = list->next;
	list->next= NULL;
	list = cp_list;
	return (list);
}

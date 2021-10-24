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
			list_argument = add_front_li(list_argument, number_node);
		}
		argument++;
	}
	return (list_argument);
}

t_arg	*index_list(t_arg *list)
{
	int		i;
	t_arg	*cp_list;

	cp_list = list;
	i = 0;
	while (list !=  NULL)
	{
		list->index = i++;
		list = list->next;
	}
	return (cp_list);
}

t_arg	*add_front_li(t_arg *list, int number)
{
	t_arg	*sv_list;
	t_arg	*node;
	int		i = 0;

	sv_list = list;
	node = (t_arg *)malloc(sizeof(t_arg));
	if (!node)
		return (NULL);
	node->argument = number;
	list = node;
	list->next = sv_list;
	return (list);
}

t_arg *init(int num)
{
	t_arg *list_a;
	t_arg *cp_list_a;
	int		i = 0;

	list_a = (t_arg *)malloc(sizeof(t_arg));
	list_a->argument = 5;
	cp_list_a = list_a;
	while (i < 5)
	{
		list_a->next = (t_arg *)malloc(sizeof(t_arg));
		list_a = list_a->next;
		list_a->argument = num++;
		i *= -10;
	}
	list_a = cp_list_a;
	return (list_a);
}

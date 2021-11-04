#include "push_swap.h"

int	strclen(char *str, int c)
{
	int	size;

	size = 0;
	while (str && str[size] != c && str[size])
		size++;
	return (size);
}

char	*copy(char *str_arg, int size)
{
	static char	str_final[12];
	int		i = 0;

	while (str_arg && size > 0)
	{
		str_final[i] = *str_arg;
		i++;
		str_arg++;
		size--;
	}
	str_final[i] = '\0';
	return (str_final);
}

int	ft_atoi(char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	if (*str == '-' ||*str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

t_arg	*translate_index_to_binary(t_arg *list)
{
	t_arg	*cp_list;
	int		array_index[10];
	int		i;
	int		o;

	cp_list = list;
	while (list)
	{
		o = 0;
		i = 9;
		while (i >= 0)
		{
			list->index_bit[o] = (list->index >> i)&1;
			++o;
			--i;
		}
		list = list->next;
	}
	list = cp_list;
	return (cp_list);
}
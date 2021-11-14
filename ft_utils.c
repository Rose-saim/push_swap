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

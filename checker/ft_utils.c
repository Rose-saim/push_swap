#include "../push_swap.h"

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

int	strclen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
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
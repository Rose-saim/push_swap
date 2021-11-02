#include "push_swap.h"

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

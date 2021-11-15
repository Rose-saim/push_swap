/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:14:38 by myrmarti          #+#    #+#             */
/*   Updated: 2021/11/15 16:55:54 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int			i;

	i = 0;
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

int	ft_atoi(char *str, t_arg *list)
{
	long int	num;
	int			sign;

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
	if (num * sign > 2147483647 || num * sign < -2147483648)
	{
		free_lst(list);
		write(1, "Error\n", 6);
		exit(0);
	}
	return (num * sign);
}

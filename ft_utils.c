/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myrmarti <myrmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:14:38 by myrmarti          #+#    #+#             */
/*   Updated: 2022/01/25 11:37:28 by myrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strclen(char *str, int c)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[size + i] && str[size + i] != c)
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

int	num_overflow(char *str)
{
	int			j;
	int			i;
	char		*string;

	j = 0;
	i = 0;
	if (str[0] != '0')
		return (0);
	string = malloc(sizeof(char) * 12);
	if (!string)
		return (0);
	if (str && (str[i] == '0' || str[i] == '-'))
	{
		if (str[i] == '-')
			++i;
		while (str[i] && str[i] == '0')
			++i;
		while (str[i + j])
		{
			string[j] = str[i + j];
			++j;
		}
		string[j] = '\0';
	}
	return (return_overflow(string, 0));
}

int	return_overflow(char *string, int c)
{
	if (strclen(string, c) > 11)
	{
		free(string);
		return (1);
	}
	free(string);
	return (0);
}

int	ft_atoi(char *str, t_arg *list)
{
	int long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (num_overflow(str))
		error_free(list);
	if (*str == '-' || *str == '+')
	{
		if (!(*(str + 1) >= '0' && *(str + 1) <= '9'))
			error_free(list);
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
		error_free(list);
	return (num * sign);
}

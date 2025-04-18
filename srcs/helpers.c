/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 03:15:54 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/15 08:37:02 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

long	find_max(long *arr, int size)
{
	long	max;
	int		i;

	max = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

long	find_min(long *arr, int size)
{
	long	min;
	int		i;

	min = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

int	find_index_in_b(long *arr, long element, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

long	*ft_realloc_src(long *src, int size)
{
	int		i;
	long	*new;

	i = 0;
	new = (long *)malloc((size - 1) * sizeof(long));
	while (i < size - 1)
	{
		new[i] = src[i + 1];
		i++;
	}
	free(src);
	return (new);
}

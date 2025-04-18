/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:46:13 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/18 09:44:00 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(long *sorted, int size, long element)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

void	increment_range(int *end, int *start)
{
	(*end)++;
	(*start)++;
}

void	push_back_to_a(t_stack *a, t_stack *b, long *sorted)
{
	int		position;
	long	max;
	int		half;

	while (b->size > 0)
	{
		half = b->size / 2;
		max = find_max(b->arr, b->size);
		position = find_index_in_b(b->arr, max, b->size);
		while (b->arr[0] != max)
		{
			if (position <= half)
				rotate(b, 'b');
			else
				reverse_rotate(b, 'b');
		}
		push(b, a, 'a');
	}
	free(sorted);
}

long	*copy_array(long *arr, int size)
{
	long	*copy;
	int		i;

	i = 0;
	copy = (long *)malloc(size * sizeof(long));
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

long	*bubble_sort(long *arr, int size)
{
	long	*sorted;
	int		i;
	int		j;
	long	tmp;

	sorted = copy_array(arr, size);
	j = 0;
	while (j <= size - 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (sorted[i] > sorted[i + 1])
			{
				tmp = sorted[i];
				sorted[i] = sorted[i + 1];
				sorted[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
	return (sorted);
}

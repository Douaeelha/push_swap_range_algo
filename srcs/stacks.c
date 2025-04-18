/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:36:19 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/18 03:24:04 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int size)
{
	t_stack	*st;

	st = (t_stack *)malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->arr = (long *)malloc(size * sizeof(long));
	if (!st->arr)
		return (free(st), NULL);
	st->size = size;
	st->cap = size;
	return (st);
}

int	stack_empty_or_full(t_stack *stk)
{
	if (stk->size == 0)
		return (0);
	else if (stk->size >= stk->cap)
		return (-1);
	else
		return (1);
}

long	peek(t_stack *stk)
{
	return (stk->arr[0]);
}

int	is_sorted(t_stack *a)
{
	int	i;

	if (!a || a->cap <= 1)
		return (1);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

long	*ft_realloc_dst(long *src, long *dst, int size)
{
	long	*new;
	int		i;

	i = 1;
	new = (long *)malloc((size + 1) * sizeof(long));
	if (!new)
		return (NULL);
	new[0] = src[0];
	while (i < size + 1)
	{
		new[i] = dst[i - 1];
		i++;
	}
	free(dst);
	return (new);
}

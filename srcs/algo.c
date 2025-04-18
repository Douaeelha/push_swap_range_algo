/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:35:33 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/18 11:35:05 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	long	top;
	long	middle;
	long	bottom;

	bottom = a->arr[2];
	middle = a->arr[1];
	top = a->arr[0];
	if (top > middle && middle > bottom) 
	{
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
	else if (top > bottom && bottom > middle) 
		rotate(a, 'a');
	else if (middle > top && top > bottom) 
		reverse_rotate(a, 'a');
	else if (middle > bottom && bottom > top) 
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (bottom > top && top > middle) 
		swap(a, 'a');
}

void	sort_four(t_stack *a, t_stack *b)
{
	long	min;

	min = find_min(a->arr, a->size);
	while (a->arr[0] != min)
		reverse_rotate(a, 'a');
	push(a, b, 'b');
	sort_three(a);
	push(b, a, 'a');
}

void	sort_five(t_stack *a, t_stack *b)
{
	long	min;

	min = find_min(a->arr, a->size);
	while (a->arr[0] != min)
		reverse_rotate(a, 'a');
	push(a, b, 'b');
	sort_four(a, b);
	push(b, a, 'a');
}
#include <stdio.h>

void	sort_chunks(t_stack *a, t_stack *b)
{
	int		index;
	int		end;
	int		start;
	long	*sorted;

	init_range(&start, &end, a->cap);
	sorted = bubble_sort(a->arr, a->cap);
	while (a->size > 0)
	{
		index = find_index(sorted, a->cap, a->arr[0]);
		if (index >= start && index <= end)
		{
			push(a, b, 'b');
			increment_range(&start, &end);
		}
		else if (index < start)
		{
			push(a, b, 'b');
			rotate(b, 'b');
			increment_range(&start, &end);
		}
		else if (index > end)
			rotate(a, 'a');
	}
	push_back_to_a(a, b, sorted);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		swap(a, 'a');
	else if (a->size == 3)
		sort_three(a);
	b = create_stack(0);
	b->cap = a->cap;
	if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else if (a->size > 5)
		sort_chunks(a, b);
	free_stack(b);
	free_stack(a);
}

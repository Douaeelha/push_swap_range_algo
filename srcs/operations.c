/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:36:34 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/18 10:16:28 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stk, char c)
{
	int	tmp;

	if (stk->size < 2)
		return ;
	tmp = stk->arr[0];
	stk->arr[0] = stk->arr[1];
	stk->arr[1] = tmp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	push(t_stack *src, t_stack *dst, char c)
{
	if (stack_empty_or_full(src) == 0 || stack_empty_or_full(dst) == -1)
		return ;
	dst->arr = ft_realloc_dst(src->arr, dst->arr, dst->cap);
	dst->size++;
	src->arr = ft_realloc_src(src->arr, src->cap);
	src->size--;
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

void	reverse_rotate(t_stack *stk, char c)
{
	int	i;

	i = stk->size -1;
	while (i > 0)
	{
		ft_swap(&stk->arr[i], &stk->arr[i - 1]);
		i--;
	}
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}

void	rotate(t_stack *stk, char c)
{
	int	i;

	if (stk->size < 2)
		return ;
	i = 0;
	while (i < stk->size - 1)
	{
		ft_swap(&stk->arr[i + 1], &stk->arr[i]);
		i++;
	}
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

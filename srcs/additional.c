/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 04:18:15 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/18 11:42:18 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(int *i, char ***splited, int *count, char *str)
{
	*count = count_args(str);
	*i = 0;
	*splited = ft_split(str, ' ');
	if (!splited)
		*splited = NULL;
}

void	double_free_error(char **splited, t_stack *stk)
{
	freeing(splited);
	error_and_free(stk);
}

void	init_range(int *start, int *end, int size)
{
	// if(size <= 100)
	// {
	// 	*end = 15;
	// 	*start = 0;
	// }
	// else 
	// 	*end = 34;
	// 	*start = 0;
	*end = 0.05 * size + 10;
	*start = 0;
}

void	ft_swap(long *a, long*b)
{
	long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_only_space(char *str)
{
	int	i;

	i = 0;
	if (*str == '\0')
		return (1);
	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}

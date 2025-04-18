/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:36:47 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/18 10:48:20 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (-1);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (!str)
		return (-1);
	else if (str[i] == '-' || str[i] == '+')
		if ((str[i + 1] < '0' || str[i + 1] > '9'))
			return (-1);
	i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	count_args(char *str)
{
	static int	count;
	char		**splited;
	static int	i;

	splited = ft_split(str, ' ');
	if (!splited)
		return (-1);
	i = 0;
	while (splited[i] && ft_validate(splited[i]) == 1)
	{
		count++;
		i++;
	}
	freeing(splited);
	if (splited[i])
		return (-1);
	return (count);
}

int	check_duplicates(long *arr, int valid_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < valid_count - 1)
	{
		j = i + 1;
		while (j < valid_count)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stack	*ft_string(char *str, t_stack *stk)
{
	int		i;
	char	**splited;
	int		count;

	init_data(&i, &splited, &count, str);
	if (count == -1 || !splited)
		freeing_and_error(splited);
	stk = create_stack(count);
	if (!stk)
		return (NULL);
	while (i < count)
	{
		stk->arr[i] = ft_atol(splited[i]);
		if (stk->arr[i] < INT_MIN || stk->arr[i] > INT_MAX)
			double_free_error(splited, stk);
		i++;
	}
	if (check_duplicates(stk->arr, count) == 1)
		double_free_error(splited, stk);
	else
		freeing(splited);
	return (stk);
}

t_stack	*ft_args(int ac, char **av, t_stack *stk)
{
	char	*joined;
	t_stack	*result;
	char	*tmp;
	int		i;

	joined = ft_strdup(av[1]);
	i = 2;
	while (ac > 1)
	{
		tmp = ft_strjoin(joined, av[i]);
		free (joined);
		joined = tmp;
		i++;
		ac--;
	}
	result = ft_string(joined, stk);
	free(joined);
	return (result);
}

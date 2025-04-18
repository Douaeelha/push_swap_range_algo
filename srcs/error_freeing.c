/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_freeing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:35:46 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/15 09:33:58 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeing(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	freeing_and_error(char **str)
{
	freeing(str);
	error();
}

void	free_stack(t_stack *st)
{
	free(st->arr);
	free(st);
}

void	error_and_free(t_stack *st)
{
	free_stack(st);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

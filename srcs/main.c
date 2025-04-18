/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:33:54 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/18 11:01:45 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 1;
	while (av[i])
	{
		if (is_only_space(av[i]))
			error();
		i++;
	}
	a = NULL;
	b = NULL;
	if (ac < 2)
		error();
	else 
		a = ft_args(ac, av, a);
	if (!a)
		free_stack(a);
	if (!is_sorted(a) && a->size > 1)
		sort(a, b);
}

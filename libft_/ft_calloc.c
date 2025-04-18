/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:14:45 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/12 05:08:32 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*s;
	size_t			n;

	n = size * count;
	if (size == 0 || count == 0)
		return (malloc(0));
	if (count > SIZE_MAX / size && size != 0)
		return (NULL);
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	s = (unsigned char *)ptr;
	while (n > 0)
	{
		*s = 0;
		s++;
		n--;
	}
	return (ptr);
}

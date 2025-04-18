/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:36:38 by delhajou          #+#    #+#             */
/*   Updated: 2024/11/24 20:14:58 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	if (s < d)
	{
		d = d + len;
		s = s + len;
		while (len--)
		{
			*(--d) = *(--s);
		}
	}
	else
	{
		ft_memcpy(d, s, len);
	}
	return (dst);
}

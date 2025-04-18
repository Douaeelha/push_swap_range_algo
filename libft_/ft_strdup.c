/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:38:16 by delhajou          #+#    #+#             */
/*   Updated: 2024/12/25 16:02:01 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strdup(const char *s)
// {
// 	char	*ptr;
// 	size_t	n;

// 	n = ft_strlen(s);
// 	ptr = (char *)malloc(n * sizeof(char) + 1);
// 	if (ptr == NULL)
// 		return (NULL);
// 	ft_memcpy(ptr, s, n);
// 	ptr[n] = '\0';
// 	return (ptr);
// }
char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	n;
	size_t	i;

	n = ft_strlen(s);
	ptr = (char *)malloc(n * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	ptr[n] = '\0';
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}

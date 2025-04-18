/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:58:10 by delhajou          #+#    #+#             */
/*   Updated: 2024/11/24 20:16:01 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	start = 0;
	if (!s1)
		return (NULL);
	if (!set || s1[0] == 0 || set[0] == 0)
		return (ft_strdup(s1));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (end == 0)
		return (ft_calloc(1, sizeof(char)));
	end--;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	new = ft_calloc(end - start + 2, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1 + start, end - start + 1);
	return (new);
}

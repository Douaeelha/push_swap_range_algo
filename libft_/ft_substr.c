/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:05:01 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/12 05:09:56 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(const char *s, unsigned int start, size_t len)
// {
// 	char	*str;
// 	size_t	i;
// 	size_t	s_len;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	s_len = ft_strlen(s);
// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (start + len > s_len)
// 		len = s_len - start;
// 	str = ft_calloc(len + 1, sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	while (i < len)
// 	{
// 		str[i] = s[i + start];
// 		i++;
// 	}
// 	return (str);
// }
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

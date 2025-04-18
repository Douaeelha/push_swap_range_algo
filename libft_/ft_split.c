/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:09:52 by delhajou          #+#    #+#             */
/*   Updated: 2025/04/18 09:21:50 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *s, char c)
{
	size_t	i;
	size_t	in_word;
	size_t	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_word_len(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (*str && *str != c)
	{
		str++;
		len++;
	}
	return (len);
}

static char	**free_array(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		arr_index;
	size_t	word_len;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	arr_index = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word_len = ft_word_len(s, c);
			arr[arr_index] = ft_substr(s, 0, word_len);
			if (!arr[arr_index++])
				return (free_array(arr, arr_index - 1));
			s += word_len;
		}
	}
	arr[arr_index] = NULL;
	return (arr);
}

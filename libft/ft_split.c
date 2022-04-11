/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:21:59 by gamonte-          #+#    #+#             */
/*   Updated: 2021/09/02 21:21:59 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	new_word;

	count = 0;
	new_word = 0;
	while (*s)
	{
		if (*s != c && new_word == 0)
		{
			new_word = 1;
			count++;
		}
		else if (*s == c)
			new_word = 0;
		s++;
	}
	return (count);
}

static size_t	ft_getwordlen(char *s, char c)
{
	size_t	i;
	size_t	c_count;

	i = 0;
	c_count = 0;
	while (*s)
	{
		if (*s != c && *s != '\0')
		{
			c_count = 1;
			i++;
		}
		else if ((*s == c && c_count != 0) || (*s == '\0' && c_count != 0))
			return (i);
		s++;
	}
	return (i);
}

static char	**ft_fill(char **new_str, char const *s, size_t words, char c)
{
	size_t	i;
	size_t	st;
	size_t	j;

	i = 0;
	st = 0;
	j = 0;
	while (j < ft_strlen((char *)s) + 1 && i < words)
	{
		if ((char)s[j] != c)
		{
			st = ft_getwordlen((char *)s + j, c);
			j += st;
			new_str[i] = ft_substr(s, (j - st), st);
			i++;
		}
		else
			j++;
	}
	return (new_str);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	size_t	words;

	if (!s)
		return (0);
	words = 0;
	words = ft_count_words(s, c);
	new_str = ft_calloc((words + 1), sizeof(char *));
	if (!new_str)
	{
		free(new_str);
		return (0);
	}
	ft_fill(new_str, s, words, c);
	return (new_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:29:59 by gamonte-          #+#    #+#             */
/*   Updated: 2022/02/09 03:20:33 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_free(char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	st;

	if (!s)
		return (0);
	st = (size_t)start;
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
	{
		free(new_str);
		return (0);
	}
	i = 0;
	while (i < len && s[st + i])
	{
		new_str[i] = s[st + i];
		i++;
	}
	new_str[i] = '\0';
	free(s);
	return (new_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:22:20 by gamonte-          #+#    #+#             */
/*   Updated: 2021/09/02 21:22:21 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!new_str)
		return (0);
	ft_memcpy(new_str, s1, s1_len);
	ft_strlcat(new_str, s2, (s1_len + s2_len + 1));
	return (new_str);
}

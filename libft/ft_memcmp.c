/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:21:34 by gamonte-          #+#    #+#             */
/*   Updated: 2021/09/02 21:21:34 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	if (n == 0)
		return (0);
	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	n -= 1;
	while (n-- && new_s1 && new_s2)
	{
		if (*new_s1 != *new_s2)
			return (*new_s1 - *new_s2);
		new_s1++;
		new_s2++;
	}
	return (*new_s1 - *new_s2);
}

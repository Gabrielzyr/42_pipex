/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:21:40 by gamonte-          #+#    #+#             */
/*   Updated: 2021/09/02 21:21:40 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*j;
	unsigned char	*z;
	size_t			i;

	if (!dest && !src)
		return (0);
	j = dest;
	z = (void *)src;
	i = 0;
	while (i < n)
	{
		j[i] = z[i];
		i++;
	}
	return (dest);
}

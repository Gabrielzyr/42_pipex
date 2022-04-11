/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 02:24:27 by gamonte-          #+#    #+#             */
/*   Updated: 2022/02/10 14:08:33 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_getnbrsize(long long unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_utoa_print(unsigned int n)
{
	unsigned int	size;
	char			*str;
	int				i;

	size = ft_getnbrsize(n);
	i = size;
	str = ft_calloc(size + 1, 1);
	if (!str)
		return (0);
	while (size)
	{
		str[(size) - 1] = (n % 10) + '0';
		n = (n / 10);
		size--;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (i);
}

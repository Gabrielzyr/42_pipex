/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversor_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 02:23:04 by gamonte-          #+#    #+#             */
/*   Updated: 2022/02/10 14:08:33 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_nbr(unsigned int nbr, char *base, unsigned int base_len)
{
	unsigned int	nbr2;

	nbr2 = (unsigned int)(nbr);
	if (nbr2 < base_len)
		write(1, &base[nbr2], 1);
	else
	{
		print_nbr(nbr2 / base_len, base, base_len);
		print_nbr(nbr2 % base_len, base, base_len);
	}
}

int	ft_convert_x(unsigned int unbr, char c)
{
	size_t	length;

	length = 0;
	if (c == 'x')
		print_nbr(unbr, "0123456789abcdef", 16);
	else
		print_nbr(unbr, "0123456789ABCDEF", 16);
	if (unbr == 0)
		return (1);
	while (unbr)
	{
		unbr = unbr / 16;
		length++;
	}
	return (length);
}

void	print_nbr_p(size_t nbr, char *base, size_t base_len)
{
	size_t	nbr2;

	nbr2 = (size_t)(nbr);
	if (nbr2 < base_len)
		write(1, &base[nbr2], 1);
	else
	{
		print_nbr_p(nbr2 / base_len, base, base_len);
		print_nbr_p(nbr2 % base_len, base, base_len);
	}
}

int	ft_convert_p(size_t unbr)
{
	size_t	length;

	ft_putstr_fd("0x", 1);
	if (!unbr)
	{
		write(1, "0", 1);
		return (3);
	}
	print_nbr_p(unbr, "0123456789abcdef", 16);
	length = 0;
	while (unbr)
	{
		unbr = unbr / 16;
		length++;
	}
	length += 2;
	return (length);
}

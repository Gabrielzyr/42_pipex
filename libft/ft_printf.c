/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 02:24:32 by gamonte-          #+#    #+#             */
/*   Updated: 2022/02/10 14:03:39 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_get_str_type(char *str, size_t ist_start, va_list args)
{
	int	length;

	length = 0;
	if (str[ist_start] == 'c')
		length = ft_convert_c(args);
	else if (str[ist_start] == 's')
		length = ft_convert_s(va_arg(args, char *));
	else if (str[ist_start] == 'd' || str[ist_start] == 'i')
		length = ft_convert_d_i(args);
	else if (str[ist_start] == 'x' || str[ist_start] == 'X')
		length = ft_convert_x(va_arg(args, unsigned int), str[ist_start]);
	else if (str[ist_start] == 'p')
		length = ft_convert_p(va_arg(args, size_t));
	else if (str[ist_start] == 'u')
		length = ft_convert_u(args);
	else if (str[ist_start] == '%')
	{
		write(1, "%", 1);
		length = 1;
	}
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	length;

	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX%", str[i]))
				length += ft_get_str_type((char *)str, i, args);
		}
		else
			length += ft_printf_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}

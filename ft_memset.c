/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:21:46 by gamonte-          #+#    #+#             */
/*   Updated: 2022/03/27 15:30:43 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char *j;

    i = 0;
    j = s;
    while (i < n)
    {
        j[i] = (unsigned char)c;
        i++;
    }
    return (s);
}

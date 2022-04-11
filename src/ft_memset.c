/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:21:46 by gamonte-          #+#    #+#             */
/*   Updated: 2022/04/11 01:01:26 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

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

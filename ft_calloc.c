/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:17:26 by gamonte-          #+#    #+#             */
/*   Updated: 2022/03/27 15:24:53 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    char *new_str;

    new_str = malloc(nmemb * size);
    if (!new_str)
        return (0);
    ft_bzero(new_str, nmemb * size);
    return (new_str);
}
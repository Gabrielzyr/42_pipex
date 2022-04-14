/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:38:59 by gamonte-          #+#    #+#             */
/*   Updated: 2022/04/15 01:54:59 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void get_cmd_paths(t_pipe *p_data, char **envp)
{
    while (*envp)
    {
        if (ft_strncmp(*envp, "PATH=", 5) == 0)
        {
            p_data->cmd_paths = ft_split(*envp + 5, ':');
            return;
        }
        envp++;
    }
    return;
}

void handle_errors(t_pipe *p_data)
{
    if (p_data->has_error == ARG_ERROR)
        exit(1);
    if (p_data->has_error == PERMISSION_ERROR)
        exit(1);
    if (p_data->has_error == INFILE_ERROR)
        exit(1);
    if (p_data->has_error == OUTFILE_ERROR)
        exit(1);
    if (p_data->has_error == CMD_NOT_FOUND)
        exit(127);
}

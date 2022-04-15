/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:20:11 by gamonte-          #+#    #+#             */
/*   Updated: 2022/04/15 16:20:34 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	check_access(t_pipe *p_data, char *path, int cmd)
{
	if (access(path, X_OK) == 0)
	{
		if (cmd == 1)
			p_data->cmds.path_1 = ft_strdup(path);
		else
		{
			p_data->cmds.path_2 = ft_strdup(path);
			free_matrix(p_data->cmd_paths);
		}
		free(path);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

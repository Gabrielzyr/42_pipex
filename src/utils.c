/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:38:59 by gamonte-          #+#    #+#             */
/*   Updated: 2022/04/15 19:09:07 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	print_cmd_error(char *str)
{
	char	*error;

	if (!str)
		ft_putstr_fd("pipex: : Command not found\n", 2);
	else
	{
		error = ft_strjoin("pipex: ", str);
		error = ft_strjoin_free(error, ": Command not found\n");
		ft_putstr_fd(error, 2);
		free(error);
	}
}

void	get_cmd_paths(t_pipe *p_data, char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			p_data->cmd_paths = ft_split(*envp + 5, ':');
			return ;
		}
		envp++;
	}
	return ;
}

void	handle_errors(int error, char *str)
{
	if (error == ARG_ERROR)
	{
		ft_printf(
			"Bad number of arguments. Please run the command as the following:\n"
			);
		ft_printf("./pipex <infile> \"<cmd1>\" | \"<cmd2>\" <output>\n");
	}
	if (error == PERMISSION_ERROR || error == INF_PERMISSION)
	{
		ft_printf("pipex: %s: Permission denied\n", str);
	}
	if (error == FILE_ERROR)
	{
		ft_printf("pipex: %s: No such file or directory\n", str);
	}
	if (error == CMD_NOT_FOUND)
	{
		print_cmd_error(str);
	}
	if (error == CMD_NULL)
	{
		print_cmd_error(str);
		exit(127);
	}
}

void	handle_cmd_error(t_pipe *p_data, int cmd)
{
	free_matrix(p_data->cmd_paths);
	if (cmd == 1)
	{
		handle_errors(CMD_NOT_FOUND, p_data->cmds.cmd_1[0]);
		free_matrix(p_data->cmds.cmd_1);
	}
	else
	{
		handle_errors(CMD_NOT_FOUND, p_data->cmds.cmd_2[0]);
		free_matrix(p_data->cmds.cmd_2);
	}
	exit(127);
}

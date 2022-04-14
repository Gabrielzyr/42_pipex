/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:38:52 by gamonte-          #+#    #+#             */
/*   Updated: 2022/04/14 20:38:53 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void get_cmd_path(t_pipe *p_data, int cmd)
{
    int i;
    char *path;

    i = 0;
    while (p_data->cmd_paths[i])
    {
        path = ft_strdup(p_data->cmd_paths[i]);
        path = ft_strjoin_free(path, "/");
        if (cmd == 1)
            path = ft_strjoin_free(path, p_data->cmds.cmd_1[0]);
        else
            path = ft_strjoin_free(path, p_data->cmds.cmd_2[0]);
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
            return ;
        }
        free(path);
        i++;
    }
    free_matrix(p_data->cmd_paths);
    if (cmd == 1)
        free_matrix(p_data->cmds.cmd_1);
    else
    {
        free_matrix(p_data->cmds.cmd_2);
    }
    exit(127);
}

void cmd_executer(t_pipe *p_data, int cmd)
{
    get_cmd_path(p_data, cmd);
    if (cmd == 1)
    {
        execve(p_data->cmds.path_1, p_data->cmds.cmd_1, p_data->envp);
    }
    else
    {
        execve(p_data->cmds.path_2, p_data->cmds.cmd_2, p_data->envp);
        // ft_putendl_fd("111FREEEE111", 2);
        free_matrix(p_data->cmds.cmd_2);
        free(p_data->cmds.path_2);
        // exit(EXIT_SUCCESS);
    }
    // exit(EXIT_SUCCESS);
}

void child_process(t_pipe *p_data)
{
    p_data->fd_infile = open(p_data->infile, O_RDONLY);
    if (p_data->fd_infile < 0)
    {
        exit(EXIT_SUCCESS);
    }
    dup2(p_data->fd_infile, STDIN_FILENO);
    dup2(p_data->fd[1], STDOUT_FILENO);
    // ft_putendl_fd(ft_strjoin("fd_before", ft_itoa(p_data->fd_infile)), 2);
    close(p_data->fd_infile);
    close(p_data->fd[0]);
    close(p_data->fd[1]);
    cmd_executer(p_data, 1);
}

void parent_process(t_pipe *p_data)
{
    close(p_data->fd[1]);
    p_data->fd_outfile = open(p_data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (p_data->fd_outfile == -1)
        exit(1);
    dup2(p_data->fd[0], STDIN_FILENO);
    dup2(p_data->fd_outfile, STDOUT_FILENO);
    close(p_data->fd_outfile);
    close(p_data->fd[0]);
    close(p_data->fd[1]);
    cmd_executer(p_data, 2);
}

void ft_pipex(t_pipe *p_data, char **argv, char **envp)
{
    pipe(p_data->fd);
    p_data->cmds.pid_1 = fork();
    if (p_data->cmds.pid_1 < 0)
        exit(EXIT_FAILURE);
    if (p_data->cmds.pid_1 == 0)
    {
        get_cmd_paths(p_data, envp);
        get_commands(p_data, argv, 1);
        child_process(p_data);
    }
    else
    {
        waitpid(p_data->cmds.pid_1, &p_data->child_status, 0);
        get_cmd_paths(p_data, envp);
        get_commands(p_data, argv, 2);
        parent_process(p_data);
    }
    exit(EXIT_SUCCESS);
}

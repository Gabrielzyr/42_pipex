#include "../headers/pipex.h"

void get_cmd_path(t_pipe *p_data, int cmd)
{
    int i;
    char *path;

    i = 0;
    while(p_data->cmd_paths[i])
    {
        path = ft_strdup(p_data->cmd_paths[i]);
        path = ft_strjoin(path, "/");
        if(cmd == 1)
            path = ft_strjoin(path, p_data->cmds.cmd_1[0]);
        else
            path = ft_strjoin(path, p_data->cmds.cmd_2[0]);
        if (access(path, X_OK) == 0)
        {
            if ( cmd == 1)
                p_data->cmds.path_1 = ft_strdup(path);
            else
                p_data->cmds.path_2 = ft_strdup(path);
            free(path);
            return ;
        }
        free(path);
        i++;
    }
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
    }
    exit(EXIT_SUCCESS);
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
    cmd_executer(p_data, 2);
}

void ft_pipex(t_pipe *p_data)
{
    pipe(p_data->fd);
    p_data->cmds.pid_1 = fork();
    if (p_data->cmds.pid_1 == 0)
        child_process(p_data);
    else
    {
        waitpid(p_data->cmds.pid_1, &p_data->child_status, 0);
        parent_process(p_data);
    }
    close(p_data->fd[0]);
    close(p_data->fd[1]);
    close(p_data->fd_outfile);
    return ;
}


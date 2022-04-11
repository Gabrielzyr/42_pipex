#include "../headers/pipex.h"

void get_cmd_path(t_pipe *p_data, int cmd)
{
    int i;
    char *path;

    i = 0;
    if (cmd) ft_printf("OK %s", p_data->cmds.cmd_1[0]);
    while(p_data->cmd_paths[i])
    {
        path = ft_strdup(p_data->cmd_paths[i]);
        path = ft_strjoin(path, "/");
        path = ft_strjoin(path, p_data->cmds.cmd_1[0]);
        // ft_printf("path: %s", path);
        // ft_printf("path %d: %s \n", i, path);
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
    // ft_printf("command no found");
}

void cmd_executer(t_pipe *p_data, int cmd)
{
    ft_printf("\nGOT here\n");
    get_cmd_path(p_data, cmd);
    if (cmd == 1)
    {
        ft_printf("GOT here %s", p_data->cmd_paths[3]);
        execve(p_data->cmds.path_1, p_data->cmds.cmd_1, p_data->envp);
    }
    else
        execve(p_data->cmds.path_2, p_data->cmds.cmd_2, p_data->envp);
    // exit(EXIT_SUCCESS);
}

void child_process(t_pipe *p_data)
{
    ft_printf("teste");
    p_data->fd_infile = open(p_data->infile, O_RDONLY);
    ft_printf("\nteste22: fd %d\n", p_data->fd_infile);
    if (p_data->fd_infile < 0)
    {
        ft_printf("\nerror\n");
        exit(EXIT_SUCCESS);
    }
    dup2(p_data->fd_infile, STDIN_FILENO);
    dup2(p_data->fd[1], STDOUT_FILENO);
    cmd_executer(p_data, 1);
}

void parent_process(t_pipe *p_data)
{
    ft_printf("all fine");
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
    int pid_status;
    ft_printf("teste here %s\n", p_data->cmds.cmd_1[0]);

    pipe(p_data->fd);
    p_data->cmds.pid_1 = fork();
    // ft_printf("pid 1 %d\n", p_data->cmds.pid_1);
    if (p_data->cmds.pid_1 == 0)
    {
        ft_printf("maybe fine\n");
        child_process(p_data);

    } 
    else
    {
        waitpid(p_data->cmds.pid_1, &pid_status, 0);
        ft_printf("all fine");
        parent_process(p_data);
    }
}


#include "../headers/pipex.h"

void get_cmd_path(t_pipe p_data, int cmd)
{
    int i;
    char *path;

    i = 0;
    while(p_data.cmd_paths[i])
    {
        path = ft_strdup(p_data.cmd_paths[i]);
        path = ft_strjoin(path, "/");
        path = ft_strjoin(path, p_data.cmds.cmd_1[0]);
            if (access(path, X_OK) == 0)
            {
                if ( cmd == 1)
                    p_data.cmds.path_1 = ft_strdup(path);
                else
                    p_data.cmds.path_2 = ft_strdup(path);
                free(path);
                return ;
            }
        i++;
    }
    printf("command no found");
}

void cmd_executer(t_pipe p_data, int cmd)
{
    get_cmd_path(p_data, cmd);
    if (cmd == 1)
        execve(p_data.cmds.path_1, p_data.cmds.cmd_1, p_data.envp);
    else
        execve(p_data.cmds.path_2, p_data.cmds.cmd_2, p_data.envp);
    exit(EXIT_SUCCESS);
}

void child_process(t_pipe p_data)
{
    p_data.fd_infile = open(p_data.infile, O_RDONLY);
    if (p_data.fd_infile < 0)
        exit(EXIT_SUCCESS);
    dup2(p_data.fd_infile, STDIN_FILENO);
    dup2(p_data.fd[1], STDOUT_FILENO);
    // check error here
}

void ft_pipex(t_pipe p_data)
{
    pipe(p_data.fd);
    p_data.cmds.pid_1 = fork();
    printf("pid 1 %d\n", p_data.cmds.pid_1);
    if (p_data.cmds.pid_1 == 0)
    {
        child_process(p_data);

    } else if(p_data.cmds.pid_1 < 0)
        printf("error pid 1");
}


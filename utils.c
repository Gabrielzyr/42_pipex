#include "pipex.h"


static void run(t_pipe data)
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        return;
    }

    int pid1 = fork();

    // printf("Got here %d %s\n", 1, data.cmds[0].cmd[0]);
    if (pid1 == 0)
    {
        printf("Got here %s\n", data.cmds[0].cmd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execve(data.cmds[0].cmd[0], data.cmds[0].cmd, data.envp);
    }
    waitpid(pid1, NULL, 0);
}

static void get_commands(t_pipe data, char **argv)
{
    int i;

    i = 1;
    while(i++ < 4)
    {
        data.cmds[i - 2].cmd = ft_split(argv[i], ' ');
        // ft_strdup(ft_strchr(data->input.envp[index], '=') + 1);
    }
    printf("command: %s \n", data.cmds[0].cmd[0]);
    printf("2command2: %s \n", data.cmds[0].cmd[1]);

    run(data);
}
void create_pipe(t_pipe data, char **argv, char **env)
{
    get_commands(data, argv);

    if (access(argv[1], F_OK))
        printf("argv: %s\n", argv[1]);
    if(env)
        printf(" ");

    // execve();
}

// void exec_cmds(t_pipe pipe);
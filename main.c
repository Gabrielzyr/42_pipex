#include "pipex.h"

static int check_args(int argc, char **args)
{
    if (argc != 5)
    {
        printf("wrong commands number");
        return 1;
    }
    if (!access(args[1], R_OK))
    {
        printf("can't access file: %s", args[1]);
        return 1;
    }  
    if (!open(args[4], O_WRONLY | O_CREAT | O_TRUNC, 0644))
    {
        printf("can't access/create output file: %s", args[4]);
        return 1;
    }
    return 0;
}

void child_process(t_pipe p_data)
{
    int infile_fd;
    infile_fd = open(p_data.infile, O_RDONLY);
    if(infile_fd == -1)
    {
        printf("error infile again");
        return ;
    }
    dup2(infile_fd, STDIN_FILENO);
    dup2(p_data.fd[1], STDOUT_FILENO);
    // close(p_data.fd[0]);
    // close(p_data.fd[1]);
}

static char **get_cmd_paths(char **envp)
{
    while (*envp)
    {
        if (ft_strncmp(*envp, "PATH=", 5) == 0)
            return (ft_split(*envp + 5, ':'));
        envp++;
    }
    printf("path error, nooooooo.....");
    return (NULL);
}

int main(int argc, char **argv, char **envp)
{
    t_pipe p_data;
    
    if (check_args(argc, argv) != 1)
    {
        pipe(p_data.fd);
        p_data.pid = fork();
        if (p_data.pid == 0)
        {
            p_data.envp = envp;
            p_data.infile = argv[1];
            // child_process(p_data);
            // create_pipe(p_data, argv, envp);
            // printf("env: %s\n", *get_paths(envp));
            p_data.cmd_paths = get_cmd_paths(envp);
            printf("ok %s \n", p_data.cmd_paths[1]);
        }
        else
        {
            waitpid(p_data.pid, NULL, 0);
            printf("teste: pid %d", p_data.pid);
        }
        // printf("envp: %s\n", *envp);
    }
    else
    {
        printf("error of pipe");
    }

    return (0);
    
}
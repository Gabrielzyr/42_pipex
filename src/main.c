#include "../headers/pipex.h"

static int check_args(t_pipe p_data, int argc, char **args)
{
    int error;
    
    error = 0;
    if (argc != 5)
    {
        printf("wrong commands number");
        error = 1;
    }
        printf("teste: %s || %d\n", args[1], access(args[1], F_OK));
    if (access(args[1], F_OK) < 0)
    {
        printf("can't access file: %s\n", args[1]);
        error = 1;
    }
    p_data.fd_outfile = open(args[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (p_data.fd_outfile < 0)
    {
        printf("can't access/create output file: %s", args[4]);
        error = 1;
    }
    printf("teste 1: %d |\n", error);
    return (error);
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

    p_data.has_error = check_args(p_data, argc, argv);
    printf("teste 2: %d |\n", p_data.has_error);
    if (p_data.has_error == 0)
    {
        p_data.envp = envp;
        p_data.infile = argv[1];
        p_data.cmd_paths = get_cmd_paths(envp);
        get_commands(p_data, argv);
        int i = -1;
        while (p_data.cmd_paths[i++])
            printf("ok %s \n", p_data.cmd_paths[i]);
        printf("ok %s \n", p_data.cmd_paths[1]);
    }
    else
    {
        printf("error of pipe");
    }

    return (0);
    
}
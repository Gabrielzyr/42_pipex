#include "../headers/pipex.h"

static int check_args(t_pipe *p_data, int argc, char **args)
{
    int error;

    p_data->fd_infile = open(args[1], O_RDONLY);
    p_data->fd_outfile = open(args[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    error = NO_ERROR;
    if (argc != 5)
        error = ARG_ERROR;
    else if (access(args[1], F_OK) == 0 && p_data->fd_infile < 0)
        error = PERMISSION_ERROR;
    if (access(args[1], F_OK) < 0) // non exist
        error = INFILE_ERROR;
    if (p_data->fd_outfile < 0) // non exist
        error = OUTFILE_ERROR;
    close(p_data->fd_infile);
    close(p_data->fd_outfile);
    return (error);
}

int main(int argc, char **argv, char **envp)
{
    t_pipe p_data;

    p_data.has_error = check_args(&p_data, argc, argv);
    ft_printf("has error? %d\n", p_data.has_error);
    if (p_data.has_error == NO_ERROR)
    {
        p_data.envp = envp;
        p_data.infile = argv[1];
        p_data.outfile = argv[4];
        ft_pipex(&p_data, argv, envp);
    }
    else
    {
        ft_printf("error of pipe");
        if (p_data.has_error == 2)
            exit(0);
        exit(1);
    }

    return (0);
}

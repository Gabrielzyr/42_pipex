/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:40:11 by gamonte-          #+#    #+#             */
/*   Updated: 2022/04/14 20:40:12 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

enum error_types
{
    NO_ERROR,
    ARG_ERROR,
    PERMISSION_ERROR,
    FILE_ERROR,
    CMD_ERROR
};

typedef struct s_cmd
{
    char    **cmd_1;
    char    **cmd_2;
    char    *path_1;
    char    *path_2;
    pid_t   pid_1;
    pid_t   pid_2;
    // char *path;
} t_cmd;

typedef struct s_pipe
{
    int     fd[2];
    int     child_status;
    t_cmd   cmds;
    char    *infile;
    char    *outfile;
    int     fd_outfile;
    int     fd_infile;
    char    *temp;
    char    **envp;
    char    **cmd_paths;
    int     has_error;

} t_pipe;

void create_pipe(t_pipe pipe, char **argv, char **env);
void get_commands(t_pipe *p_data, char **argv, int cmd);
void ft_pipex(t_pipe *p_data, char **argv, char **envp);
void free_matrix(char **matrix);
void get_cmd_paths(t_pipe *p_data, char **envp);

#endif
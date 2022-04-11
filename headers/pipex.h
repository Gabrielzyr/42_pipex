#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

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
void get_commands(t_pipe p_data, char **argv);

// char *ft_strdup(const char *s);
// char *ft_strjoin(char const *s1, char const *s2);
// char **ft_split(char const *s, char c);
// void *ft_calloc(size_t nmemb, size_t size);
// char *ft_substr(char const *s, unsigned int start, size_t len);
// size_t ft_strlen(const char *s);
// void *ft_memset(void *s, int c, size_t n);
// void ft_bzero(void *s, size_t n);
// int ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
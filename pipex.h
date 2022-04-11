#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_cmd
{
    char **cmd;
    // char *path;
} t_cmd;

typedef struct s_pipe
{
    pid_t   pid;
    int     fd[2];
    t_cmd   cmds[2];
    char    *infile;
    char    *outfile;
    char    *temp;
    char    **envp;
    char    **cmd_paths;

} t_pipe;

void create_pipe(t_pipe pipe, char **argv, char **env);
char **ft_split(char const *s, char c);

void *ft_calloc(size_t nmemb, size_t size);
char *ft_substr(char const *s, unsigned int start, size_t len);
size_t ft_strlen(const char *s);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
int ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
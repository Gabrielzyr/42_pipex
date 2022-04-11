#include "../headers/pipex.h"

char *replace_char(char *str, char replace, char new_char)
{
    int i;
    char *new_str;

    new_str = ft_strdup(str);
    i = 0;
    while(new_str[i])
    {
        if (new_str[i] == '\'')
            while(new_str[i] != '\'')
            {
                if (new_str[i] == replace)
                    new_str[i] = new_char;
                i++;
            }
        i++;
    }
    return (new_str);
}

void get_commands(t_pipe *p_data, char **argv)
{
    char *cmd;

    cmd = replace_char(argv[2], ' ', 1);
    p_data->cmds.cmd_1 = ft_split(cmd, ' ');
    free(cmd);
    if (p_data->cmds.cmd_1 == NULL)
    {
        ft_printf("error");
        exit(EXIT_FAILURE);
    }
    cmd = replace_char(argv[3], ' ', 1);
    p_data->cmds.cmd_2 = ft_split(cmd, ' ');
    // ft_printf("cmd: %s | %s\n", p_data->cmds.cmd_1[0], p_data->cmds.cmd_2[0]);
    free(cmd);

    return ;
}

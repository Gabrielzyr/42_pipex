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
    // ft_printf("new_str: %s\n", new_str);
    return (new_str);
}

void get_commands(t_pipe *p_data, char **argv)
{
    char *cmd;

    // ft_printf("cmds %s\n", argv[2]);
    cmd = replace_char(argv[2], ' ', 1);
    ft_printf("teste: %s\n", ft_split(cmd, ' ')[0]);
    p_data->cmds.cmd_1 = ft_split(cmd, ' ');
    ft_printf("here: %s\n", p_data->cmds.cmd_1[0]);
        free(cmd);
    if (p_data->cmds.cmd_1 == NULL)
    {
        ft_printf("error");
        exit(EXIT_FAILURE);
    }
    cmd = replace_char(argv[3], ' ', 1);
    p_data->cmds.cmd_2 = ft_split(cmd, ' ');
    free(cmd);

    return ;
}

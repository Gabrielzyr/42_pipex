#include "../headers/pipex.h"

char *replace_char(char *str, char replace, char new_char)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == '\'')
            while(str[i] != '\'')
            {
                if (str[i] == replace)
                    str[i] = new_char;
                i++;
            }
        i++;
    }
    printf("str: %s\n", str);
    return (str);
}

void get_commands(t_pipe p_data, char **argv)
{
    char *cmd;

    printf("cmds %s\n", argv[2]);
    cmd = replace_char(argv[2], ' ', 1);
    p_data.cmds.cmd_1 = ft_split(cmd, ' ');
    free(cmd);
    if (p_data.cmds.cmd_1 == NULL)
    {
        printf("error");
    }
    cmd = replace_char(argv[3], ' ', 1);
    p_data.cmds.cmd_2 = ft_split(cmd, ' ');
    free(cmd);

    return ;
}

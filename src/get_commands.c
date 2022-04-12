#include "../headers/pipex.h"

char *replace(char *str, char replace, char new_char)
{
    int i;
    char *new_str;

    new_str = ft_strdup(str);
    i = 0;
    while(new_str[i])
    {
        if (new_str[i] == '\'')
        {
            i++;
            while(new_str[i] != '\'')
            {
                if (new_str[i] == replace)
                    new_str[i] = new_char;
                i++;
            }
        }
        i++;
    }
    return (new_str);
}

void revert_replace(char **split)
{
    int i;
    int j;
    char *tmp;
    i = 0;

    while (split[i])
    {
        j = 0;
        while (split[i][j])
        {
            if (split[i][j] == 1)
                split[i][j] = ' ';
            j++;
            if (split[i][j] == '\'')
            {
                tmp = ft_strtrim(split[i], "'");
                free(split[i]);
                split[i] = tmp;
            }
        }
        i++;
    }
}

void get_commands(t_pipe *p_data, char **argv, int cmd)
{
    char *tmp_cmd;

    if (cmd == 1)
    {
        tmp_cmd = replace(argv[2], ' ', 1);
        p_data->cmds.cmd_1 = ft_split(tmp_cmd, ' ');
        revert_replace(p_data->cmds.cmd_1);
        free(tmp_cmd);
        return;
    }
    tmp_cmd = replace(argv[3], ' ', 1);
    p_data->cmds.cmd_2 = ft_split(tmp_cmd, ' ');
    revert_replace(p_data->cmds.cmd_2);
    free(tmp_cmd);
}

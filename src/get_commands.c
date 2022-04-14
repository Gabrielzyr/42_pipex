/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:38:46 by gamonte-          #+#    #+#             */
/*   Updated: 2022/04/14 20:38:48 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

char *replace(char *str, char replace, char new_char)
{
    int i;
    char *new_str;

    new_str = ft_strdup(str);
    i = 0;
    while (new_str[i])
    {
        if (new_str[i] == '\'')
        {
            i++;
            while (new_str[i] != '\'')
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
    char *tmp2;
    i = 0;

    while (split[i])
    {
        j = 0;
        while (split[i][j])
        {
            if (split[i][j] == 1)
            {
                tmp = replace(split[i], 1, ' ');
                tmp2 = ft_strtrim(tmp, "'");
                free(split[i]);
                split[i] = tmp2;
                free(tmp);
                break;
            }
            j++;
        }
        i++;
    }
}



void get_commands(t_pipe *p_data, char **argv, int cmd)
{
    char *tmp_cmd;
    if (cmd == 1)
    {
        if (ft_strlen(argv[2]) == 0)
        {
            ft_putstr_fd("Bad command", 2);
            exit(1);
        };
        tmp_cmd = replace(argv[2], ' ', 1);
        p_data->cmds.cmd_1 = ft_split(tmp_cmd, ' ');
        revert_replace(p_data->cmds.cmd_1);
        if (p_data->cmds.cmd_1[0] == NULL)
        {
            ft_putstr_fd("Bad command2\n", 2);
            exit(1);
        }
        free(tmp_cmd);
        return;
    }
    // ft_printf("teste: %s\n\n\n",argv[3]);
    if (ft_strlen(argv[3]) == 0)
    {
        ft_putstr_fd("Bad command\n", 2);
        exit(1);
    };
    tmp_cmd = replace(argv[3], ' ', 1);
    p_data->cmds.cmd_2 = ft_split(tmp_cmd, ' ');
    revert_replace(p_data->cmds.cmd_2);
    if (p_data->cmds.cmd_2[0] == NULL)
    {
        ft_putstr_fd("Bad command3\n", 2);
        exit(1);
    }
    free(tmp_cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:38:46 by gamonte-          #+#    #+#             */
/*   Updated: 2022/04/15 17:24:24 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static char	*replace(char *str, char replace, char new_char)
{
	int		i;
	char	*new_str;

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

static void	revert_replace(char **split)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;

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
				break ;
			}
			j++;
		}
		i++;
	}
}

void	get_commands(t_pipe *p_data, char **argv, int cmd)
{
	char	*tmp_cmd;

	if (cmd == 1)
	{
		if (ft_strlen(argv[2]) == 0)
			handle_errors(CMD_NULL, argv[2]);
		tmp_cmd = replace(argv[2], ' ', 1);
		p_data->cmds.cmd_1 = ft_split(tmp_cmd, ' ');
		revert_replace(p_data->cmds.cmd_1);
		if (p_data->cmds.cmd_1[0] == NULL)
			handle_errors(CMD_NULL, p_data->cmds.cmd_1[0]);
		free(tmp_cmd);
		return ;
	}
	if (ft_strlen(argv[3]) == 0)
		handle_errors(CMD_NULL, argv[3]);
	tmp_cmd = replace(argv[3], ' ', 1);
	p_data->cmds.cmd_2 = ft_split(tmp_cmd, ' ');
	revert_replace(p_data->cmds.cmd_2);
	if (p_data->cmds.cmd_2[0] == NULL)
		handle_errors(CMD_NULL, p_data->cmds.cmd_2[0]);
	free(tmp_cmd);
}

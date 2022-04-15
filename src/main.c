/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamonte- <gamonte-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:17:39 by gamonte-          #+#    #+#             */
/*   Updated: 2022/04/15 19:12:03 by gamonte-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static void	check_files_access(t_pipe *p_data, char **args)
{
	if (access(args[1], F_OK) == 0 && p_data->fd_infile < 0)
	{
		p_data->has_error = INF_PERMISSION;
		handle_errors(p_data->has_error, args[1]);
	}
	else if (access(args[1], F_OK) < 0)
	{
		p_data->has_error = FILE_ERROR;
		handle_errors(p_data->has_error, args[1]);
	}
	if (access(args[4], F_OK) == 0 && p_data->fd_outfile < 0)
	{
		p_data->has_error = PERMISSION_ERROR;
		handle_errors(p_data->has_error, args[4]);
	}
	else if (p_data->fd_outfile < 0)
	{
		p_data->has_error = FILE_ERROR;
		handle_errors(p_data->has_error, args[4]);
	}
}

static void	check_args(t_pipe *p_data, int argc, char **args)
{
	p_data->fd_infile = open(args[1], O_RDONLY);
	p_data->fd_outfile = open(args[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	p_data->has_error = NO_ERROR;
	if (argc != 5)
	{
		p_data->has_error = ARG_ERROR;
		handle_errors(p_data->has_error, NULL);
	}
	else
		check_files_access(p_data, args);
	close(p_data->fd_infile);
	close(p_data->fd_outfile);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	p_data;

	check_args(&p_data, argc, argv);
	if (p_data.has_error == NO_ERROR)
	{
		p_data.envp = envp;
		p_data.infile = argv[1];
		p_data.outfile = argv[4];
		ft_pipex(&p_data, argv, envp);
	}
	else
	{
		if (p_data.has_error == INF_PERMISSION)
			exit(0);
		exit(1);
	}
	return (0);
}

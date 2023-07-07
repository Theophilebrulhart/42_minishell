/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:30:57 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/28 16:58:05 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	exec_echo_redir(t_cmd *cmd)
{
	if (cmd->cmd_path[1] || cmd->outfile > 0)
	{
		if (cmd->cmd_path[1])
		{
			if (cmd->cmd_path[1][0] == '-' &&
				echo_all_n_check(cmd->cmd_path[1]))
				ft_write_echo(cmd, echo_n_check(cmd), 0);
			else
				ft_write_echo(cmd, 1, 1);
		}
	}
	else
		printf("\n");
}

void	redirection(t_cmd *cmd, t_pipex *pipex, int id)
{
	pipex->id_child = ft_realloc(pipex->id_child, 1, cmd, pipex);
	if (!pipex->id_child)
		free_all(pipex, cmd);
	if (cmd->outfile > 0 && !cmd->nbr_pipe)
		pipex->nbr_id++;
	pipex->id_child[pipex->nbr_id - 1] = fork();
	if (pipex->id_child[pipex->nbr_id - 1] < 0)
		free_all(pipex, cmd);
	if (pipex->id_child[pipex->nbr_id - 1] == 0)
	{
		builtin_fd(cmd, pipex, id);
		exec_echo_redir(cmd);
		exit (0);
	}
}

void	write_echo(t_cmd *cmd)
{
	if (cmd->cmd_path[1][0] == '-' && echo_all_n_check(cmd->cmd_path[1]))
		ft_write_echo(cmd, echo_n_check(cmd), 0);
	else
		ft_write_echo(cmd, 1, 1);
}

int	ft_echo(t_cmd *cmd, t_pipex *pipex, int id)
{
	if ((cmd->outfile != 0 && cmd->outfile > 0) || cmd->nbr_pipe)
	{
		redirection(cmd, pipex, id);
		return (1);
	}
	if (cmd->cmd_path[1] == NULL)
	{
		printf("\n");
		pipex->id_child = ft_realloc(pipex->id_child, 1, cmd, pipex);
		g_return_status = 0;
		return (1);
	}
	else
		write_echo(cmd);
	g_return_status = 0;
	return (1);
}

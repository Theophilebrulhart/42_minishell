/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:03:12 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/27 11:13:41 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	closing_first_child_pipe(t_cmd *cmd, t_pipex *pipex)
{
	int	i;
	int	j;

	i = 1;
	while (i < cmd->nbr_pipe)
	{
		j = 0;
		while (j < 2)
		{
			close(pipex->fd_pipe[i][j]);
			j++;
		}
		i++;
	}
}

void	first_child(t_pipex *pipex, t_cmd *cmd)
{
	closing_first_child_pipe(cmd, pipex);
	if (cmd->infile > 0)
	{
		dup2(cmd->infile, STDIN_FILENO);
		close(cmd->infile);
	}
	close(pipex->fd_pipe[0][0]);
	if (cmd->outfile != 1 && cmd->outfile > 0)
	{
		dup2(cmd->outfile, STDOUT_FILENO);
		close(pipex->fd_pipe[0][1]);
		close(cmd->outfile);
	}
	else
	{
		dup2(pipex->fd_pipe[0][1], STDOUT_FILENO);
		close(pipex->fd_pipe[0][1]);
	}
	execve(pipex->cmd_path, &cmd->cmd_path[0], cmd->env);
	exit(127);
}

void	closing_middle_pipe(t_pipex *pipex, t_cmd *cmd, int id)
{
	int	i;
	int	j;

	i = 0;
	while (i < cmd->nbr_pipe)
	{
		j = 0;
		while (j < 2)
		{
			if (i == id - 1)
			{
				if (j == 1)
					close(pipex->fd_pipe[i][j]);
			}
			else if (i == id)
			{
				if (j == 0)
					close(pipex->fd_pipe[i][j]);
			}
			else
				close(pipex->fd_pipe[i][j]);
			j++;
		}
		i++;
	}
}

void	middle_child_file(t_pipex *pipex, t_cmd *cmd, int id)
{
	if (cmd->infile > 0)
	{
		dup2(cmd->infile, STDIN_FILENO);
		close(pipex->fd_pipe[id - 1][0]);
		close(cmd->infile);
	}
	if (cmd->infile < 0)
	{
		dup2(pipex->fd_pipe[id - 1][0], STDIN_FILENO);
		close(pipex->fd_pipe[id - 1][0]);
	}
	if (cmd->outfile != 1 && cmd->outfile > 0)
	{
		dup2(cmd->outfile, STDOUT_FILENO);
		close(cmd->outfile);
		if (id < cmd->nbr_pipe - 1)
			close(pipex->fd_pipe[id][1]);
	}
}

void	middle_child(t_pipex *pipex, t_cmd *cmd, int id)
{
	closing_middle_pipe(pipex, cmd, id);
	middle_child_file(pipex, cmd, id);
	if (id < cmd->nbr_pipe)
	{
		dup2(pipex->fd_pipe[id][1], STDOUT_FILENO);
		close(pipex->fd_pipe[id][1]);
	}
	execve(pipex->cmd_path, &cmd->cmd_path[0], cmd->env);
	exit (127);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:03:12 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/10 15:21:02 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closing_first_child_pipe(t_cmd *cmd, t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	while (i < cmd->nbr_pipe)
	{
		j = 0;
		while (pipex->fd_pipe[i][j])
		{
			close(pipex->fd_pipe[i][j]);
			j++;
		}
		i++;
	}
}

void	first_child(t_pipex *pipex, t_cmd *cmd)
{
	int	infile;
	int	outfile;

	closing_first_child_pipe(cmd, pipex);
	if (cmd->infile)
	{
		infile_redirection(cmd, pipex, &infile);
		close(pipex->fd_pipe[0][0]);
		close(infile);
	}
	if (cmd->outfile)
	{
		printf("outfile dans le first child\n\n");
		outfile_redirection(cmd, pipex, &outfile);
		close(pipex->fd_pipe[0][1]);
		close(outfile);
	}
	if (!cmd->outfile)
	{
		printf("\n\n pas de outfile dans le first child\n\n");
		dup2(pipex->fd_pipe[0][1], STDOUT_FILENO);
		close(pipex->fd_pipe[0][1]);
		printf("\n\nMOI ON ME VOIT PAS \n\n");
	}
	printf("\non peut plus ecrire ici\n\n");
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
		while (pipex->fd_pipe[i][j])
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

void	middle_child(t_pipex *pipex, t_cmd *cmd, int id)
{
	int	fd_outfile;
	int	fd_infile;

	fd_outfile = 0;
	closing_middle_pipe(pipex, cmd, id);
	if (cmd->infile)
	{
		infile_redirection(cmd, pipex, &fd_infile);
		close(pipex->fd_pipe[id - 1][0]);
	}
	if (!cmd->infile)
	{
		dup2(pipex->fd_pipe[id - 1][0], STDIN_FILENO);
		close(pipex->fd_pipe[id - 1][0]);
	}
	if (cmd->outfile)
	{
		printf("id = %d\n", id);
		printf("outfile dans le middle child\n");
		outfile_redirection(cmd, pipex, &fd_outfile);
		printf("fd_outfile : %d\n", fd_outfile);
		close(pipex->fd_pipe[id][1]);
		close(fd_outfile);
	}
	if (!cmd->outfile && id < cmd->nbr_pipe)
	{
		dup2(pipex->fd_pipe[id][1], STDOUT_FILENO);
		close(pipex->fd_pipe[id][1]);
	}
	printf("j-'ecris ou ?\n");
	execve(pipex->cmd_path, &cmd->cmd_path[0], cmd->env);
	exit (127);
}

// void	last_child(t_pipex *pipex, t_cmd *cmd)
// {
// 	fd_outfile = 0;
// 	dup2(pipex->fd_pipe[cmd->nbr_pipe - 1][0], STDIN_FILENO);
// 	close(pipex->fd_pipe[cmd->nbr_pipe - 1][0]);
// 	if (cmd->outfile)
// 	{
// 		fd_outfile = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 		if (fd_outfile == -1)
// 			error_exit(pipex, "zsh: cannot open : ", pipex->outfile);
// 	}
// 	dup2(fd_outfile, STDOUT_FILENO);
// 	close(pipex->fd_pipe[cmd->nbr_pipe - 1][1]);
// 	execve(pipex->cmd_path, &cmd->cmd_path[0], cmd->env);
// 	exit(127);
// }

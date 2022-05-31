/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:03:12 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/05/12 15:42:31 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 1;
	while (i < pipex->argc - 4)
	{
		j = 0;
		while (pipex->fd_pipe[i][j])
		{
			close(pipex->fd_pipe[i][j]);
			j++;
		}
		i++;
	}
	pipex->fd_pipe[0][0] = open(pipex->infile, O_RDONLY, 0777);
	if (pipex->fd_pipe[0][0] == -1)
		error_exit(pipex, "no such file or directory", pipex->infile);
	dup2(pipex->fd_pipe[0][0], STDIN_FILENO);
	close (pipex->fd_pipe[0][0]);
	dup2(pipex->fd_pipe[0][1], STDOUT_FILENO);
	close(pipex->fd_pipe[0][1]);
	execve(pipex->cmd_path[0], &pipex->cmd[0][0], pipex->env);
	exit(127);
}

void	closing_middle_pipe(t_pipex *pipex, int id)
{
	int	i;
	int	j;

	i = 0;
	while (i < pipex->argc - 4)
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

void	middle_child(t_pipex *pipex, int id)
{
	closing_middle_pipe(pipex, id);
	dup2(pipex->fd_pipe[id - 1][0], STDIN_FILENO);
	close(pipex->fd_pipe[id - 1][0]);
	dup2(pipex->fd_pipe[id][1], STDOUT_FILENO);
	close(pipex->fd_pipe[id][1]);
	execve(pipex->cmd_path[id], &pipex->cmd[id][0], pipex->env);
	exit (127);
}

void	last_child(t_pipex *pipex)
{
	int	i;
	int	j;
	int	fd_outfile;

	i = 0;
	while (i < pipex->argc - 5 && pipex->argc > 4)
	{
		j = 0;
		while (pipex->fd_pipe[i][j])
		{
			close(pipex->fd_pipe[i][j]);
			j++;
		}
		i++;
	}
	dup2(pipex->fd_pipe[pipex->nbr_pipe - 1][0], STDIN_FILENO);
	close(pipex->fd_pipe[pipex->nbr_pipe - 1][0]);
	fd_outfile = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_outfile == -1)
		error_exit(pipex, "zsh: cannot open : ", pipex->outfile);
	dup2(fd_outfile, STDOUT_FILENO);
	close(pipex->fd_pipe[pipex->nbr_pipe - 1][1]);
	execve(pipex->cmd_path[pipex->argc - 4], &pipex->cmd[pipex->argc - 4][0],
		pipex->env);
	exit(127);
}

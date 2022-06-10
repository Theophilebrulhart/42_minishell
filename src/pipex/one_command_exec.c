/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:38:51 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/10 14:11:31 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../../includes/include.h"

void	command_exec(t_cmd *cmd, t_pipex *pipex)
{
	int	fd_infile;
	int	fd_outfile;

	if (cmd->infile)
	{
		infile_redirection(cmd, pipex, &fd_infile);
		close(fd_infile);
	}
	if (cmd->outfile)
	{
		outfile_redirection(cmd, pipex, &fd_outfile);
		close(fd_outfile);
	}
	execve(pipex->cmd_path, &cmd->cmd_path[0], cmd->env);
	exit (127);
}

void	one_command_exec(t_pipex *pipex, t_cmd *cmd)
{
	is_builtin(cmd);
	pipex->cmd_path = parsing_command_path(pipex, cmd);
	pipex->id_child[0] = fork();
	if (pipex->id_child[0] < 0)
		free_all(pipex, cmd);
	if (pipex->id_child[0] == 0)
		command_exec(cmd, pipex);
	wait_all(pipex, cmd);
	free_all(pipex, cmd);
}

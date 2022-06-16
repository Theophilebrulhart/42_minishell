/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:38:51 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/13 16:46:38 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../../includes/include.h"

void	command_exec(t_cmd *cmd, t_pipex *pipex)
{
	//int	fd_infile;
	//int	fd_outfile;

	if (cmd->infile_int)
	{
		printf("la ca marche\n");
		dup2(cmd->infile_int, STDIN_FILENO);
		close(cmd->infile_int);
	}
	printf("infile fini\n");
	if (cmd->outfile_int != 0 && cmd->outfile_int > 0)
	{
		printf("on est dans le outfile\n");
		dup2(cmd->outfile_int, STDOUT_FILENO);
		close(cmd->outfile_int);
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

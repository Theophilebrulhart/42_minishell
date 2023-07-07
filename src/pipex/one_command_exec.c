/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:38:51 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/30 20:11:38 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	command_exec(t_cmd *cmd, t_pipex *pipex)
{
	if (cmd->infile)
	{
		dup2(cmd->infile, STDIN_FILENO);
		close(cmd->infile);
	}
	if (cmd->outfile != 0 && cmd->outfile > 0)
	{
		dup2(cmd->outfile, STDOUT_FILENO);
		close(cmd->outfile);
	}
	execve(pipex->cmd_path, cmd->cmd_path, cmd->env);
	exit (127);
}

void	one_command_wait(t_cmd *cmd, t_pipex *pipex)
{
	int	status_return;

	waitpid(pipex->id_child[0], &status_return, 0);
	if (WIFEXITED(status_return))
	{
		g_return_status = WEXITSTATUS(status_return);
		if (g_return_status == 127)
		{
			printf("bash: %s: command not found\n", cmd->cmd_path[0]);
			free_all(pipex, cmd);
		}
	}
}

void	one_command_exec(t_pipex *pipex, t_cmd *cmd)
{
	if (!is_builtin(cmd, pipex, 0))
	{
		pipex->cmd_path = parsing_command_path(pipex, cmd);
		if (pipex->cmd_path == NULL)
		pipex->cmd_path = cmd->cmd_path[0];
		pipex->id_child = ft_realloc(pipex->id_child, 1, cmd, pipex);
		pipex->id_child[0] = fork();
		if (pipex->id_child[0] < 0)
			free_all(pipex, cmd);
		if (pipex->id_child[0] == 0)
		{
			set_child_signals();
			command_exec(cmd, pipex);
		}
		else
			unset_parent_signals();
	}
	if (pipex->id_child || (cmd->outfile != 0 && cmd->outfile > 0))
		one_command_wait(cmd, pipex);
	free_all(pipex, cmd);
}

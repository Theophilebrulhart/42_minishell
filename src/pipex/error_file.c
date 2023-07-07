/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:32:41 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/30 20:32:55 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	free_pipex(t_cmd *cmd, t_pipex *pipex)
{
	int	i;

	i = 0;
	if (cmd->cmd_path[0])
	{
		if (pipex->id_child)
			free(pipex->id_child);
		i = 0;
		while (i < cmd->nbr_pipe)
		{
			free(pipex->fd_pipe[i]);
			i++;
		}
		if (cmd->nbr_pipe)
			free(pipex->fd_pipe);
	}
}

void	free_env(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->env)
	{
		while (cmd->env[i])
		{
			free(cmd->env[i]);
			i++;
		}
		free(cmd->env);
	}
}

void	free_list(t_cmd *cmd)
{
	int			i;

	i = 0;
	while (cmd->cmd_path[i])
	{
		free(cmd->cmd_path[i]);
		i++;
	}
	free(cmd->cmd_path);
	i = 0;
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	if (cmd)
	{
		while (cmd->next)
		{
			tmp = (cmd)-> next;
			free_list(cmd);
			cmd = tmp;
		}
		free_list(cmd);
	}
}

void	free_all(t_pipex *pipex, t_cmd *cmd)
{
	free_pipex(cmd, pipex);
	if (cmd->cmd_path[0] && !ft_strncmp(cmd->cmd_path[0], "exit",
			ft_strlen(cmd->cmd_path[0]))
		&& !cmd->nbr_pipe)
	{
		free_cmd(cmd);
		free_env(cmd);
		printf("exit\n");
		exit (g_return_status);
	}
	free_cmd(cmd);
	mainparsing(cmd);
}

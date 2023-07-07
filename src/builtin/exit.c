/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:07:34 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/30 20:43:51 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	close_fd_exit(t_cmd *cmd, t_pipex *pipex, int id)
{
	int	i;
	int	j;

	i = 0;
	if (id == cmd->nbr_pipe)
	{
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
}

void	exit_redirection(t_cmd *cmd, t_pipex *pipex, int id)
{
	pipex->id_child = ft_realloc(pipex->id_child, 1, cmd, pipex);
	if (!pipex->id_child)
		free_all(pipex, cmd);
	pipex->id_child[id] = fork();
	if (id == cmd->nbr_pipe)
		close_fd_exit(cmd, pipex, id);
	if (pipex->id_child[id] < 0)
		free_all(pipex, cmd);
	if (pipex->id_child[id] == 0)
	{
		ft_str_is_num(cmd, cmd->cmd_path[1]);
		if (cmd->cmd_path[1])
			exit (ft_atoi(cmd->cmd_path[1]));
		exit (0);
	}
}

int	ft_exit(t_cmd *cmd, t_pipex *pipex, int id)
{
	int	status_return;

	exit_redirection(cmd, pipex, id);
	if (cmd->nbr_pipe == 0)
	{
		waitpid(pipex->id_child[0], &status_return, 0);
		if (WIFEXITED(status_return))
			g_return_status = WEXITSTATUS(status_return);
		free_all(pipex, cmd);
	}
	return (1);
}

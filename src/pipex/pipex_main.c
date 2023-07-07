/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:18:05 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/07/12 12:24:34 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	child_forking(t_cmd *cmd, t_pipex *pipex, int i)
{
	pipex->id_child = ft_realloc(pipex->id_child, 1, cmd, pipex);
	if (!pipex->id_child)
		free_all(pipex, cmd);
	pipex->cmd_path = parsing_command_path(pipex, cmd);
	if (pipex->cmd_path == NULL)
		pipex->cmd_path = cmd->cmd_path[0];
	pipex->id_child[i] = fork();
	if (pipex->id_child[i] < 0)
		free_all(pipex, cmd);
}

void	forking_middle_child(t_pipex *pipex, t_cmd *cmd)
{
	int		i;
	char	**tmp_env;

	i = 1;
	while (i <= pipex->nbr_pipe)
	{
		if (!is_builtin(cmd, pipex, i))
		{
			child_forking(cmd, pipex, i);
			if (pipex->id_child[i] == 0)
			{
				middle_child(pipex, cmd, i);
				set_child_signals();
			}
			else
				unset_parent_signals();
		}
		i++;
		tmp_env = cmd->env;
		cmd = cmd->next;
		if (cmd)
			cmd->env = tmp_env;
	}
}

void	ft_pipex_suite(t_cmd *cmd, t_pipex *pipex)
{
	char	**tmp_env;

	tmp_env = cmd->env;
	cmd = cmd->next;
	cmd->env = tmp_env;
	forking_middle_child(pipex, cmd);
	close_parent_fd(pipex, cmd);
	wait_all(pipex, cmd);
}

int	ft_pipex(t_cmd *cmd, t_pipex *pipex)
{
	pipex->nbr_pipe = 0;
	while (pipex->nbr_pipe < cmd->nbr_pipe)
	{
		if (pipe(pipex->fd_pipe[pipex->nbr_pipe]) < 0)
			free_all(pipex, cmd);
		pipex->nbr_pipe++;
	}
	pipex->nbr_id = 1;
	if (!is_builtin(cmd, pipex, 0))
	{
		child_forking(cmd, pipex, 0);
		if (pipex->id_child[0] == 0)
		{	
			set_child_signals();
			first_child(pipex, cmd);
		}
		else
			unset_parent_signals();
	}
	ft_pipex_suite(cmd, pipex);
	return (g_return_status);
}

int	pipex_start(t_cmd *cmd)
{
	t_pipex	pipex;

	if (cmd->cmd_path[0] == NULL)
		free_all(&pipex, cmd);
	pipex.id_child = NULL;
	pipex.nbr_id = 0;
	if (cmd->nbr_pipe == 0)
		one_command_exec(&pipex, cmd);
	pipex.fd_pipe = pipe_allocation(cmd->nbr_pipe);
	g_return_status = ft_pipex(cmd, &pipex);
	free_all(&pipex, cmd);
	printf("pipex return 0");
	return (0);
}

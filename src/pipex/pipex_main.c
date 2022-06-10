/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:18:05 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/10 15:09:48 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../../includes/include.h"

int	**pipe_allocation(int nbr_pipe)
{
	int	**fd_pipe;
	int	*fd_single_pipe;
	int	i;

	i = 0;
	fd_pipe = malloc((nbr_pipe) * sizeof(*fd_pipe));
	if (!fd_pipe)
		return (0);
	while (i < nbr_pipe)
	{
		fd_single_pipe = malloc(2 * sizeof(*fd_single_pipe));
		if (!fd_single_pipe)
			return (0);
		fd_pipe[i] = fd_single_pipe;
		i++;
	}
	return (fd_pipe);
}

void	close_parent_fd(t_pipex *pipex, t_cmd *cmd)
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

void	forking_middle_child(t_pipex *pipex, t_cmd *cmd)
{
	int	i;

	i = 1;
	while (i < cmd->nbr_pipe + 1)
	{
		pipex->cmd_path = parsing_command_path(pipex, cmd);
		printf("cmd->nbr_pipe : %d\n", cmd->nbr_pipe);
		is_builtin(cmd);
		pipex->id_child[i] = fork();
		if (pipex->id_child[i] < 0)
			free_all(pipex, cmd);
		if (pipex->id_child[i] == 0)
			middle_child(pipex, cmd, i);
		i++;
		// avancer d'un noeud dans la liste
	}
}

void	ft_pipex(t_cmd *cmd, t_pipex *pipex)
{
	while (pipex->nbr_pipe < cmd->nbr_pipe)
	{
		if (pipe(pipex->fd_pipe[pipex->nbr_pipe]) < 0)
			free_all(pipex, cmd);
		pipex->nbr_pipe++;
	}
	is_builtin(cmd);
	pipex->cmd_path = parsing_command_path(pipex, cmd);
	pipex->id_child[0] = fork();
	if (pipex->id_child[0] < 0)
		free_all(pipex, cmd);
	if (pipex->id_child[0] == 0)
		first_child(pipex, cmd);
	//avancer d'un noeuds dans la liste
	forking_middle_child(pipex, cmd);
	close_parent_fd(pipex, cmd);
	wait_all(pipex, cmd);
}

int	pipex_start(t_cmd *cmd)
{
	t_pipex	pipex;

	pipex.id_child = malloc((cmd->nbr_pipe + 1) * sizeof(*pipex.id_child));
	if (!pipex.id_child)
		return (1);
	if (cmd->nbr_pipe == 0)
		one_command_exec(&pipex, cmd);
	pipex.fd_pipe = pipe_allocation(cmd->nbr_pipe); 
	ft_pipex(cmd, &pipex);
	// free_all(&pipex);
	return (0);
}

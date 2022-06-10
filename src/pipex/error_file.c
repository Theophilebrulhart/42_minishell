/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:32:41 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/10 13:52:44 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_pipex *pipex, t_cmd *cmd)
{
	int	i;

	i = 0;
	free(pipex->id_child);
	while (i < cmd->nbr_pipe)
	{
		free(pipex->fd_pipe[i]);
		i++;
	}
	if (cmd->nbr_pipe)
		free(pipex->fd_pipe);
	exit (0);
}

void	error_exit(t_pipex *pipex, t_cmd *cmd, char *err_message, char *prob)
{
	printf("zsh: %s : %s\n", err_message, prob);
	free_all(pipex, cmd);
}

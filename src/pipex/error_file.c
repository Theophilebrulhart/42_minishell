/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:32:41 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/05/31 15:04:03 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	free(pipex->id_child);
	while (i < pipex->argc - 3)
	{
		j = 0;
		while (pipex->cmd[i][j])
		{
			free(pipex->cmd[i][j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < pipex->nbr_pipe)
	{
		free(pipex->fd_pipe[i]);
		i++;
	}
	free(pipex->fd_pipe);
	exit (0);
}

void	error_exit(t_pipex *pipex, char *err_message, char *prob)
{
	printf("zsh: %s : %s\n", err_message, prob);
	free_all(pipex);
}

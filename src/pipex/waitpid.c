/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:16:18 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/10 10:32:15 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_all(t_pipex *pipex, t_cmd *cmd)
{
	int	i;
	int	status;
	int	status_return;

	i = 0;
	while (i < cmd->nbr_pipe + 1)
	{
		waitpid(pipex->id_child[i], &status, 0);
		if (WIFEXITED(status))
		{
			status_return = WEXITSTATUS(status);
			if (status_return != 0)
				free_all(pipex);
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:16:18 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/13 15:34:37 by theophilebr      ###   ########.fr       */
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
		printf("on attend\n");
		waitpid(pipex->id_child[i], &status, 0);
		if (WIFEXITED(status))
		{
			status_return = WEXITSTATUS(status);
			if (status_return != 0)
				free_all(pipex, cmd);
		}
		i++;
	}
}

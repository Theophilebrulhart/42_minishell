/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:16:18 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/05/12 15:13:14 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_all(t_pipex *pipex)
{
	int	i;
	int	status;
	int	status_return;

	i = 0;
	while (i < pipex->argc - 3)
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

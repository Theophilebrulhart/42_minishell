/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:16:18 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/30 20:13:51 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	wait_all(t_pipex *pipex, t_cmd *cmd)
{
	int	i;
	int	status_return;

	i = 0;
	if (pipex->id_child)
	{
		while (i < pipex->nbr_id)
		{
			waitpid(pipex->id_child[i], &status_return, 0);
			if (WIFEXITED(status_return))
			{
				g_return_status = WEXITSTATUS(status_return);
				if (g_return_status == 127)
				{
					printf("bash: command not found\n");
				}
			}
			i++;
		}
	}
	free_all(pipex, cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:57:28 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/13 15:23:01 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	close_parent_fd(t_pipex *pipex, t_cmd *cmd)
{
	int	i;
	int	j;

	i = 0;
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

void	error_exit(t_pipex *pipex, t_cmd *cmd, char *err_message, char *prob)
{
	(void)cmd;
	(void)pipex;
	printf("bash: %s : %s\n", prob, err_message);
}

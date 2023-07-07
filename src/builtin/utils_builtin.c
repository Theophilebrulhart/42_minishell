/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:55:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/28 17:00:31 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	ft_str_is_num(t_cmd *cmd, char *str)
{
	int	i;

	i = 0;
	(void)cmd;
	if (!str)
		return ;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			printf("bash: exit: %s: numeric argument required\n", str);
			exit (255);
		}
		i++;
	}
}

void	close_cd_fd(t_cmd *cmd, t_pipex *pipex, int id)
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

void	builtin_fd(t_cmd *cmd, t_pipex *pipex, int id)
{
	if (id < cmd->nbr_pipe || cmd->outfile > 0)
	{
		if (cmd->outfile != 0 && cmd->outfile > 0)
		{
			dup2(cmd->outfile, STDOUT_FILENO);
			close(cmd->outfile);
		}
		else
		{
			dup2(pipex->fd_pipe[id][1], STDOUT_FILENO);
			close(pipex->fd_pipe[id][1]);
		}
	}
}

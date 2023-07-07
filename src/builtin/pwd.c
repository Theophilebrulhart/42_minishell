/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:47:12 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/13 15:22:49 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	pwd_redirection(t_cmd *cmd, t_pipex *pipex, int id)
{
	char	pwd[256];

	pipex->id_child = ft_realloc(pipex->id_child, 1, cmd, pipex);
	if (!pipex->id_child)
		free_all(pipex, cmd);
	if (cmd->outfile > 0 && !cmd->nbr_pipe)
		pipex->nbr_id++;
	pipex->id_child[pipex->nbr_id - 1] = fork();
	if (pipex->id_child[pipex->nbr_id - 1] < 0)
		free_all(pipex, cmd);
	if (pipex->id_child[pipex->nbr_id - 1] == 0)
	{
		builtin_fd(cmd, pipex, id);
		if (getcwd(pwd, sizeof(pwd)) == NULL)
			free_all(pipex, cmd);
		printf("%s\n", pwd);
		exit (0);
	}
}

int	ft_pwd(t_cmd *cmd, t_pipex *pipex, int id)
{
	char	pwd[256];

	if ((cmd->outfile != 0 && cmd->outfile > 0) || cmd->nbr_pipe)
		pwd_redirection(cmd, pipex, id);
	else
	{
		if (getcwd(pwd, sizeof(pwd)) == NULL)
			free_all(pipex, cmd);
		printf("%s\n", pwd);
	}
	g_return_status = 0;
	return (1);
}

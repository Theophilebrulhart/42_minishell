/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:04:51 by theophilebr       #+#    #+#             */
/*   Updated: 2022/10/25 14:35:29 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"	

void	redirection_env(t_cmd *cmd, t_pipex *pipex, int id, int i)
{
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
		i = 0;
		if (cmd->cmd_path[1] != NULL)
		{
			printf("env : %s: No such file or directory\n", cmd->cmd_path[1]);
			exit (127);
		}
		while (cmd->env[++i] != NULL)
		{
			if (value_check(cmd->env[i]))
				printf("%s\n", cmd->env[i]);
		}
		exit (0);
	}
}

int	value_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	ft_env(t_cmd *cmd, t_pipex *pipex, int id)
{
	int	i;

	i = 0;
	if (env_var_exist(cmd, "PATH"))
		return (1);
	if ((cmd->outfile != 0 && cmd->outfile > 0) || cmd->nbr_pipe)
		redirection_env(cmd, pipex, id, i);
	else
	{
		if (cmd->cmd_path[1] != NULL)
		{
			printf("env : %s: No such file or directory\n", cmd->cmd_path[1]);
			g_return_status = 127;
			return (1);
		}
		i = 0;
		while (cmd->env[i])
		{
			if (value_check(cmd->env[i]))
				printf("%s\n", cmd->env[i]);
			i++;
		}
	}
	g_return_status = 0;
	return (1);
}

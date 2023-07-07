/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtin_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:52:05 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/28 12:14:05 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	cd_go_to_dir(t_cmd *cmd, t_pipex *pipex)
{
	int	i;

	if (cmd->cmd_path[2])
	{
		i = 2;
		while (cmd->cmd_path[i])
		{
			cmd->cmd_path[1] = ft_strjoin(cmd->cmd_path[1], " ");
			cmd->cmd_path[1] = ft_strjoin(cmd->cmd_path[1], cmd->cmd_path[i]);
			i++;
		}
	}
	if (chdir(cmd->cmd_path[1]) < 0)
	{
		printf("bash: cd: %s: No such file or directory\n",
			cmd->cmd_path[1]);
		g_return_status = 1;
		free_all(pipex, cmd);
	}
}

int	env_var_exist(t_cmd *cmd, char *str)
{
	int	i;

	i = 0;
	while (cmd->env)
	{
		if (cmd->env[i] == NULL)
		{
			printf("bash: env: No such file or directory\n");
			return (1);
		}
		if (!ft_strncmp_unset(cmd->env[i], str))
			return (0);
		i++;
	}
	return (1);
}

int	not_valid_identifier(t_cmd *cmd, t_pipex *pipex, int i)
{
	(void)pipex;
	(void)cmd;
	g_return_status = i;
	if (i)
		printf("export : not a valid identifier\n");
	return (1);
}

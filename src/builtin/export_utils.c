/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:37:40 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/28 16:53:32 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	export_arg(t_cmd *cmd, t_pipex *pipex, int i)
{
	int	j;

	if (cmd->nbr_pipe)
	{
		pipex->id_child = ft_realloc(pipex->id_child, 1, cmd, pipex);
		if (!pipex->id_child)
			free_all(pipex, cmd);
		return (1);
	}
	if (!already_exist(cmd, i))
	{
		j = env_allocation(cmd, pipex, 1);
		cmd->env[j - 1] = ft_strdup(cmd->cmd_path[i]);
		cmd->env[j] = NULL;
		g_return_status = 0;
	}
	return (0);
}

int	ft_strncmp_export(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*s1 && *s2 && *s1 == *s2 && *s2 != '=')
	{
		s1++;
		s2++;
		i++;
	}
	if (*s1 != '\0')
		return (1);
	if (*s2 == '=')
	{
		s2--;
		s1--;
	}
	if (*s1 - *s2 == 0)
		return (0);
	return (1);
}

int	already_exist(t_cmd *cmd, int j)
{
	int		i;
	char	tmp[256];
	char	*tmp_free;

	i = 0;
	while (cmd->cmd_path[j][i] && cmd->cmd_path[j][i] != '=')
	{
		tmp[i] = cmd->cmd_path[j][i];
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	while (cmd->env[i])
	{
		if (!ft_strncmp_export(tmp, cmd->env[i]))
		{
			tmp_free = cmd->env[i];
			cmd->env[i] = ft_strdup(cmd->cmd_path[j]);
			g_return_status = 0;
			free(tmp_free);
			return (1);
		}
		i++;
	}
	return (0);
}

void	export_redirection(t_cmd *cmd, t_pipex *pipex, int id, int i)
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
		if (export_special_arg(cmd, pipex, i))
		{
			printf("on est la\n");
			exit (1);
		}
		exit (0);
	}
}

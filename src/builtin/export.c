/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:09:56 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/28 16:57:19 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	is_bigger(char *str, char *env)
{
	int	i;

	i = 0;
	if (!str || env == NULL)
		return (0);
	while (str[i] && env[i])
	{
		if (str[i] == '=' && env[i])
			return (0);
		if ((str[i] - env[i]) > 0)
			return (1);
		if ((str[i] - env[i]) < 0)
			return (0);
		i++;
	}
	if (env[i] == '\0' && str[i])
		return (1);
	return (0);
}

void	comparaison(char **tmp_env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tmp_env[i + 1])
	{
		if (tmp_env[i] != NULL && is_bigger(tmp_env[i], tmp_env[i + 1]))
		{
			tmp = tmp_env[i + 1];
			tmp_env[i + 1] = tmp_env[i];
			tmp_env[i] = tmp;
			i = -1;
		}
		i++;
	}
}

int	export_without_arg(t_cmd *cmd, t_pipex *pipex)
{
	char	**tmp_env;
	int		i;

	i = 0;
	while (cmd->env[i])
		i++;
	tmp_env = malloc((i + 1) * sizeof(*tmp_env));
	if (!tmp_env)
		free_all(pipex, cmd);
	tmp_env[i] = NULL;
	i = -1;
	while (cmd->env[i++ + 1])
		tmp_env[i] = ft_strdup(cmd->env[i]);
	comparaison(tmp_env);
	i = 0;
	while (tmp_env[i])
	{
		if (tmp_env[i][0] == '_' && tmp_env[i][1] == '=')
			i++;
		printf("declare -x %s\n", tmp_env[i]);
		free(tmp_env[i]);
		i++;
	}
	free(tmp_env);
	return (1);
}

int	export_special_arg(t_cmd *cmd, t_pipex *pipex, int j)
{
	int	i;

	i = 0;
	if (cmd->cmd_path[1] == NULL)
	{
		g_return_status = 0;
		return (export_without_arg(cmd, pipex));
	}
	if (cmd->cmd_path[j][0] == '_')
	{
		if (!cmd->cmd_path[j][1])
			return (not_valid_identifier(cmd, pipex, 0));
		if (cmd->cmd_path[j][1] == '=')
			return (not_valid_identifier(cmd, pipex, 0));
	}
	if (!ft_isalpha(cmd->cmd_path[j][0]) && cmd->cmd_path[j][0] != '_')
		return (not_valid_identifier(cmd, pipex, 1));
	while (cmd->cmd_path[j][i] != '=' && cmd->cmd_path[j][i])
	{
		if (!ft_isalnum(cmd->cmd_path[j][i]) && cmd->cmd_path[j][i] != '_')
			return (not_valid_identifier(cmd, pipex, 1));
		i++;
	}
	return (0);
}

int	ft_export(t_cmd	*cmd, t_pipex *pipex, int id)
{
	int	i;

	i = 1;
	if (cmd->cmd_path[1] == NULL)
	{
		g_return_status = 0;
		return (export_without_arg(cmd, pipex));
	}
	while (cmd->cmd_path[i])
	{
		if ((cmd->outfile != 0 && cmd->outfile > 0) || cmd->nbr_pipe)
		{
			export_redirection(cmd, pipex, id, i);
			if ((cmd->outfile <= 0 || cmd->nbr_pipe == 0))
				return (1);
		}
		if (!export_special_arg(cmd, pipex, i))
		{
			if (export_arg(cmd, pipex, i))
				return (1);
		}			
		i++;
	}
	return (1);
}

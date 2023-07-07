/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:47:48 by theophilebr       #+#    #+#             */
/*   Updated: 2022/10/28 14:32:21 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	unset_redirection(t_cmd *cmd, t_pipex *pipex, int id, int j)
{
	int	i;

	i = 0;
	pipex->id_child = ft_realloc(pipex->id_child, 1, cmd, pipex);
	if (!pipex->id_child)
		free_all(pipex, cmd);
	pipex->id_child[id] = fork();
	if (pipex->id_child[id] < 0)
		free_all(pipex, cmd);
	if (pipex->id_child[id] == 0)
	{
		if (!valid_identifier(cmd, j))
			exit (1);
		exit (0);
	}
}

int	ft_strncmp_unset(const char *s1, const char *s2)
{
	int	i;
	int	j;

	j = 0;
	if (!s1)
		return (0);
	while (s1[j] != '\0' && s1[j] != '=')
		j++;
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if ((s1[i] != '=' || ft_strlen(s2) != j))
	{
		if (s1[i] - s2[i] == 0)
			return (0);
		return (1);
	}
	return (0);
}

void	env_unset(t_cmd *cmd, t_pipex *pipex, int unset)
{
	char	**tmp_env;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (cmd->env[i])
		i++;
	tmp_env = malloc((i) * sizeof(*tmp_env));
	if (!tmp_env)
		free_all(pipex, cmd);
	tmp_env[i - 1] = NULL;
	k = 0;
	j = 0;
	while (k < i)
	{
		if (k == unset)
			k++;
		tmp_env[j] = cmd->env[k];
		j++;
		k++;
	}
	free(cmd->env[unset]);
	free(cmd->env);
	cmd->env = tmp_env;
}

int	valid_identifier(t_cmd *cmd, int j)
{
	int	i;

	i = 0;
	if (!cmd->cmd_path[1])
		return (1);
	while (cmd->cmd_path[j][i])
	{
		if ((!ft_isalnum(cmd->cmd_path[j][i]) && cmd->cmd_path[j][i] != '_')
			|| (!ft_isalpha(cmd->cmd_path[j][0]) && cmd->cmd_path[j][0] != '_'
			&& cmd->cmd_path[j][0] == '$'))
		{
			printf("bash : unset: `%s': not a valid identifier\n",
				cmd->cmd_path[j]);
			g_return_status = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_unset(t_cmd *cmd, t_pipex *pipex, int id)
{
	int	j;

	j = 1;
	while (cmd->cmd_path[j])
	{
		if ((cmd->outfile != 0 && cmd->outfile > 0) || cmd->nbr_pipe)
		{
			unset_redirection(cmd, pipex, id, j);
			if (cmd->outfile <= 0)
				return (1);
		}
		if (cmd->cmd_path[1] == NULL)
		{
			g_return_status = 0;
			return (1);
		}
		if (valid_identifier(cmd, j))
			unset_check(cmd, pipex, j);
		j++;
	}
	g_return_status = 0;
	return (1);
}

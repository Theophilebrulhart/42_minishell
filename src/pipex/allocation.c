/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:14:42 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/13 15:22:54 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	env_allocation(t_cmd *cmd, t_pipex *pipex, int new)
{
	int		i;
	int		j;
	char	*old_env;
	char	**tmp_env;

	tmp_env = NULL;
	i = 0;
	while (cmd->env[i])
		i++;
	tmp_env = malloc((i + new + 1) * sizeof(*cmd->env));
	if (!tmp_env)
		free_all(pipex, cmd);
	tmp_env[i + new] = NULL;
	j = 0;
	while (j < i)
	{
		old_env = cmd->env[j];
		tmp_env[j] = ft_strdup(cmd->env[j]);
		if (new)
			free(old_env);
		j++;
	}	
	cmd->env = tmp_env;
	return (i + new);
}

int	**pipe_allocation(int nbr_pipe)
{
	int	**fd_pipe;
	int	*fd_single_pipe;
	int	i;

	i = 0;
	fd_pipe = malloc((nbr_pipe) * sizeof(*fd_pipe));
	if (!fd_pipe)
		return (0);
	while (i < nbr_pipe)
	{
		fd_single_pipe = malloc(2 * sizeof(*fd_single_pipe));
		if (!fd_single_pipe)
			return (0);
		fd_pipe[i] = fd_single_pipe;
		i++;
	}
	return (fd_pipe);
}

int	*ft_realloc(int *str, int size, t_cmd *cmd, t_pipex *pipex)
{
	int		i;
	int		*new_str;

	if (pipex->id_child == NULL)
	{
		new_str = malloc(1 * sizeof(*pipex->id_child));
		if (!new_str)
			free_all(pipex, cmd);
	}
	else
	{
		i = 0;
		pipex->nbr_id += size;
		new_str = malloc((pipex->nbr_id) * sizeof(*new_str));
		if (!new_str)
			free_all(pipex, cmd);
		while (i < pipex->nbr_id - 1)
		{
			new_str[i] = pipex->id_child[i];
			i++;
		}
		free(str);
	}
	return (new_str);
}

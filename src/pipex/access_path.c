/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:12:17 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/13 15:22:53 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

char	*path_str(t_pipex *pipex, t_cmd *cmd)
{
	t_env	env;

	env.path = "PATH";
	env.j = 0;
	while (cmd->env[env.j])
	{
		env.i = 0;
		while (cmd->env[env.j][env.i] == env.path[env.i])
			env.i++;
		if (env.path[env.i] == '\0')
			break ;
		env.j++;
	}
	if (cmd->env[env.j] == NULL)
		return (NULL);
	env.path_str = malloc((ft_strlen(cmd->env[env.j]) - 4)
			* sizeof(*path_str));
	if (!env.path_str)
		free_all(pipex, cmd);
	env.i = 0;
	env.t = 5;
	while (cmd->env[env.j][env.t])
		env.path_str[env.i++] = cmd->env[env.j][env.t++];
	env.path_str[env.i] = '\0';
	return (env.path_str);
}

char	*access_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = malloc((i + j) * sizeof(*str) + 2);
	if (str == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		str[i++] = s1[j++];
	j = 0;
	str[i++] = '/';
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*access_test(t_pipex *pipex, t_cmd *cmd, char **all_path)
{
	char	*str_path;
	int		i;
	int		j;

	i = 0;
	while (all_path[i])
	{
		j = 0;
		str_path = access_strjoin(all_path[i], cmd->cmd_path[0]);
		if (!access(str_path, F_OK))
			return (str_path);
		free(str_path);
		i++;
	}
	(void)pipex;
	return (cmd->cmd_path[0]);
}

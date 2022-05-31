/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:12:17 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/05/12 16:19:04 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_str(t_pipex *pipex)
{
	t_env	env;

	env.path = "PATH";
	env.j = 0;
	while (pipex->env[env.j])
	{
		env.i = 0;
		while (pipex->env[env.j][env.i] == env.path[env.i])
			env.i++;
		if (env.path[env.i] == '\0')
			break ;
		env.j++;
	}
	env.t = 5;
	env.path_str = malloc((ft_strlen(pipex->env[env.j]) - 4)
			* sizeof(*path_str));
	if (!env.path_str)
		free_all(pipex);
	env.i = 0;
	while (pipex->env[env.j][env.t])
		env.path_str[env.i++] = pipex->env[env.j][env.t++];
	env.path_str[env.i] = '\0';
	return (env.path_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
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

char	*access_test(t_pipex *pipex, char **all_path, int cmd_nbr)
{
	char	*str_path;
	int		i;
	int		j;

	i = 0;
	while (all_path[i])
	{
		j = 0;
		str_path = ft_strjoin(all_path[i], pipex->cmd[cmd_nbr][0]);
		if (!access(str_path, F_OK))
			return (str_path);
		free(str_path);
		i++;
	}
	error_exit(pipex, "command not found", pipex->cmd[cmd_nbr][0]);
	return (NULL);
}

char	**path_creation(t_pipex *pipex, char **all_path)
{
	int		i;
	char	**final_path;

	final_path = malloc((pipex->argc - 2) * sizeof(*final_path));
	if (!final_path)
		free_all(pipex);
	final_path[pipex->argc - 2] = 0;
	i = 0;
	while (i < pipex->argc - 3)
	{
		final_path[i] = access_test(pipex, all_path, i);
		i++;
	}
	i = 0;
	while (all_path[i])
	{
		free(all_path[i]);
		i++;
	}
	return (final_path);
}

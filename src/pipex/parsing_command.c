/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:37:57 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/28 15:51:36 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	***parsing_command(int argc, char **argv)
{
	int		i;
	int		t;
	char	***cmd;

	cmd = malloc((argc - 2) * sizeof(*cmd));
	if (!cmd)
		return (NULL);
	cmd[argc - 2] = 0;
	i = 0;
	t = 2;
	while (i < argc - 3)
	{
		cmd[i] = ft_split(argv[t], ' ');
		t++;
		i++;
	}
	return (cmd);
}

char	*parsing_command_path(t_pipex *pipex, t_cmd *cmd)
{
	char	*path_s;
	char	**all_path;
	char	*final_path;

	path_s = path_str(pipex, cmd);
	if (path_s == NULL)
		return (NULL);
	all_path = ft_split(path_s, ':');
	free(path_s);
	final_path = access_test(pipex, cmd, all_path);
	free(all_path);
	return (final_path);
}

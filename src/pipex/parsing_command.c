/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:37:57 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/10 11:34:07 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../../includes/include.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
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
	(void) cmd;
	char	*path_s;
	char	**all_path;
	char	*final_path = NULL;

	path_s = path_str(pipex, cmd);
	all_path = ft_split(path_s, ':');
	free(path_s);
	final_path = access_test(pipex, cmd, all_path);
	free(all_path);
	return (final_path);
}

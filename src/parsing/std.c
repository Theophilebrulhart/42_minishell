/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:58:08 by pyammoun          #+#    #+#             */
/*   Updated: 2022/10/28 15:43:13 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	ft_outfile(t_tmp *tmp, char *file)
{
	tmp->out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
}

void	ft_infile(t_tmp *tmp, char *file, t_info *info, char *cmd)
{
	tmp->in = open(file, O_RDONLY, 0777);
	if (tmp->in == -1)
		error_infile(tmp, file, info, cmd);
}

void	ft_append(t_tmp *tmp, char *file)
{
	tmp->out = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
}

void	ft_here_doc(t_tmp *tmp, char *file)
{
	char	*line;
	int		fd[2];

	line = malloc(0);
	pipe(fd);
	while (line)
	{
		free(line);
		line = readline("> ");
		if (!ft_strncmp(file, line, ft_strlen(line)))
			break ;
		else
		{
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
		}
	}
	close(fd[1]);
	tmp->in = fd[0];
}

int	redirechoose(t_tmp *tmp, char *cmd, int c, t_info *info)
{
	int	i;

	i = c;
	while (cmd[i])
	{
		if (cmd[i] == '>' && cmd[i + 1] != '>')
			ft_outfile(tmp, getfile2(cmd, i));
		else if (cmd[i] == '<' && cmd[i + 1] != '<')
			ft_infile(tmp, getfile1(cmd, i), info, cmd);
		else if (cmd[i] == '>' && cmd[i + 1] == '>')
			ft_append(tmp, getfile2(cmd, i));
		else if (cmd[i] == '<' && cmd[i + 1] == '<')
			ft_here_doc(tmp, getfile1(cmd, i));
		return (find_space(cmd, i));
		i++;
	}
	return (i);
}

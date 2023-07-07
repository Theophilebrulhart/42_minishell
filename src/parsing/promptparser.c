/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   promptparser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:57:08 by pyammoun          #+#    #+#             */
/*   Updated: 2022/10/30 20:14:46 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

_Bool	spacechecker(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else
			return (false);
	}
	return (true);
}

_Bool	endwithpipe(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i >= 0)
	{
		if (line[i] == ' ')
			i--;
		else if (line[i] == '|')
			return (true);
		else
			return (false);
	}
	return (true);
}

int	endspace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else
			return (i);
	}
	return (0);
}

int	starter_separation(char *line, t_cmd *cmd)
{
	int		i;
	char	**tabinput;
	t_info	info;

	i = -1;
	info.nb = ft_sep_countu(line, '|');
	info.cmd = cmd;
	tabinput = ft_splitu(line, '|');
	info.tmp = malloc(sizeof(struct s_tmp) * info.nb);
	while (++i < info.nb)
		struct_setter(&info.tmp[i], tabinput[i], &info);
	splitinfo(&info, cmd);
	return (1);
}

int	promptchecker(char *line, t_cmd *cmd)
{	
	if (spacechecker(line) == true)
		return (0);
	if (evenquote(line) == true)
		return (0);
	if (endwithpipe(line) == true)
		return (0);
	line = ft_substr(line, endspace(line),
			ft_strlen(line) - endspace(line));
	line = checkerforenv(line, cmd);
	if (!starter_separation(line, cmd))
		printf("error\n");
	return (1);
}

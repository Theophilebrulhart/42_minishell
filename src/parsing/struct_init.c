/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:57:17 by pyammoun          #+#    #+#             */
/*   Updated: 2022/10/30 20:20:04 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	struct_setter(t_tmp *tmp, char *cmd, t_info	*info)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	tmp->cmd = malloc(sizeof(char *) * (cmd_counter(cmd) + 1));
	while (cmd[i])
	{
		if (cmd[i] == '>' || cmd[i] == '<')
			i += redirechoose(tmp, cmd, i, info);
		else if (cmd[i] == 34)
			i += dobble_quote(tmp, cmd, i, &c);
		else if (cmd[i] == 39)
			i += single_quote(tmp, cmd, i, &c);
		else if (cmd[i] == ' ')
			i++;
		else
		{
			tmp->cmd[c] = ft_substr(cmd, i, find_spacu(cmd, i));
			c = c + 1;
			i += find_spacu(cmd, i);
		}
	}
	tmp->cmd[c] = NULL;
}

void	score_checker(char *cmd, t_utils *utl, int n)
{
	utl->i++;
	utl->c++;
	while (cmd[utl->i] != n)
		utl->i++;
	utl->i++;
}

void	cmd_passer(char *cmd, t_utils *utl)
{
	if (cmd[utl->i] == 39)
		score_checker(cmd, utl, 39);
	else if (cmd[utl->i] == 34)
		score_checker(cmd, utl, 34);
	else if (cmd[utl->i] == '<' || cmd[utl->i] == '>')
	{
		while (cmd[utl->i] == '<' || cmd[utl->i] == '>' || cmd[utl->i] == ' ')
			utl->i++;
		while (cmd[utl->i] != ' ' && cmd[utl->i])
			utl->i++;
	}
	else if (cmd[utl->i] == ' ' && cmd[utl->i])
		utl->i++;
	else
	{
		utl->c++;
		while (cmd[utl->i] != ' ' && cmd[utl->i])
			utl->i++;
	}	
}

int	cmd_counter(char *cmd)
{
	t_utils	utl;

	utl.i = 0;
	utl.c = 0;
	while (cmd[utl.i])
		cmd_passer(cmd, &utl);
	return (utl.c);
}

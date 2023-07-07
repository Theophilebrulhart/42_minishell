/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:47:17 by pyammoun          #+#    #+#             */
/*   Updated: 2022/10/30 20:03:08 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	set_up_chain(t_cmd *cmd, t_tmp *tmp, int nb, int i)
{
	cmd->cmd_path[i] = NULL;
	cmd->nbr_pipe = nb;
	cmd->infile = tmp->in;
	cmd->outfile = tmp->out;
	cmd->next = NULL;
}

t_cmd	*lstnew(t_cmd *cmd, t_tmp *tmp, int nb, t_cmd *first)
{
	int		i;
	int		j;
	char	**cmdcontent;

	i = 0;
	j = 0;
	cmdcontent = tmp->cmd;
	while (cmdcontent[i])
		i++;
	cmd = malloc(sizeof(t_cmd));
	cmd->cmd_path = malloc(sizeof(char *) * (i + 1));
	if (first == NULL)
		cmd->first = cmd;
	else
		cmd->first = first;
	i = -1;
	while (cmdcontent[++i])
		cmd->cmd_path[i] = ft_strdup(cmdcontent[i]);
	set_up_chain(cmd, tmp, nb, i);
	return (cmd);
}

void	lstadd_back(t_cmd **alst, t_cmd *new)
{
	if (!alst || !new)
		return ;
	if (!*alst)
		*alst = new;
	else
		lstlast(*alst)->next = new;
}

t_cmd	*lstlast(t_cmd *list)
{
	if (list == NULL)
		return (0);
	while (list -> next)
		list = list -> next;
	return (list);
}

int	lstsize(t_cmd *lst)
{
	int	count;

	count = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

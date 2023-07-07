/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:53:05 by pyammoun          #+#    #+#             */
/*   Updated: 2022/10/28 14:04:41 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

char	*is_in_env(char *tabinput, t_cmd *cmd, t_utils *utl, char *retour)
{
	if (ft_strncmp_env(cmd->env, ft_substr(tabinput, utl->l, utl->j - utl->l)))
	{
		return (ft_strjoin((ft_strjoin(ft_substr(tabinput,
							0, utl->l - 1), (replaceenv(ft_substr(tabinput,
									utl->l, utl->j - utl->l), utl->j - utl->l,
								cmd)))), ft_substr(tabinput, utl->j,
					(ft_strlen(tabinput) - utl->j))));
	}
	else if (tabinput[utl->l] == '?')
	{
		retour = ft_strjoin((ft_strjoin(ft_substr(tabinput,
							0, utl->l - 1), ft_itoa(g_return_status))),
				ft_substr(tabinput, utl->l + 1,
					(ft_strlen(tabinput) - utl->l + 1)));
		utl->j = utl->l;
		return (retour);
	}
	else
	{
		retour = ft_strjoin(ft_substr(tabinput, 0, utl->l - 1),
				ft_substr(tabinput, utl->j, ft_strlen(tabinput) - utl->j));
		utl->j = utl->l;
		return (retour);
	}
}

char	*checkerforenv(char *tabinput, t_cmd *cmd)
{
	t_utils	utl;
	char	*retour;

	retour = NULL;
	setup_struct2(&utl);
	while (++utl.j < ft_strlen(tabinput))
	{
		areyouin2(tabinput[utl.j], &utl);
		if (utl.i == 0)
			areyouin(tabinput[utl.j], &utl);
		if (tabinput[utl.j] == '$' && utl.a == 0
			&& tabinput[utl.j + 1] != ' ' && tabinput[utl.j + 1] != 34
			&& tabinput[utl.j + 1] != 39 && tabinput[utl.j + 1] != '\0')
		{
			utl.j++;
			utl.l = utl.j;
			while (tabinput[utl.j] && checkend(tabinput[utl.j]))
				utl.j++;
			tabinput = is_in_env(tabinput, cmd, &utl, retour);
		}
	}
	return (tabinput);
}

char	*replaceenv(char *envtmp, int l, t_cmd *cmd)
{
	int		i;
	char	*newstring;

	i = 0;
	newstring = NULL;
	while (cmd->env[i])
	{
		if (ft_strncmp(ft_substr(cmd->env[i], 0, l), envtmp, l) == 0)
		{
			newstring = ft_substr(cmd->env[i], l + 1,
					(ft_strlen(cmd->env[i]) - (l + 1)));
			return (newstring);
		}
		i++;
	}
	return (NULL);
}

char	**environnementalloc(t_cmd *cmd)
{
	int		i;
	char	**tmp;	

	i = 0;
	while (cmd->env[i])
	{
		i++;
	}
	tmp = malloc(sizeof(char *) * (i + 1));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (cmd->env[i])
	{
		tmp[i] = ft_strdup(cmd->env[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcommand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:44:51 by pyammoun          #+#    #+#             */
/*   Updated: 2022/10/28 14:03:07 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	ft_strncmp_env(char **env, char *s)
{
	int	i;
	int	j;
	int	t;

	t = 0;
	j = 0;
	if (!env)
		return (0);
	while (env[t])
	{	
		j = 0;
		while (env[t][j] != '\0' && env[t][j] != '=')
			j++;
		i = 0;
		while (env[t][i] && s[i] && env[t][i] == s[i])
			i++;
		if (i == j)
			return (1);
		t++;
	}
	return (0);
}

void	setup_struct2(t_utils *utl)
{
	utl->l = 0;
	utl->a = 0;
	utl->j = -1;
	utl->i = 0;
}

int	checkend(char c)
{
	if (c == '_')
		return (1);
	if (c <= 'z' && c >= 'a')
		return (1);
	if (c <= 'Z' && c >= 'A')
		return (1);
	return (0);
}

void	areyouin(char c, t_utils *utl)
{
	if (c == 39 && utl->a == 0)
		utl->a = 1;
	else if (c == 39 && utl->a == 1)
		utl->a = 0;
}

void	areyouin2(char c, t_utils *utl)
{
	if (c == 34 && utl->i == 0)
		utl->i = 1;
	else if (c == 34 && utl->i == 1)
		utl->i = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_trimmer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:12:44 by pyammoun          #+#    #+#             */
/*   Updated: 2022/10/19 20:12:45 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	dobble_quote(t_tmp *tmp, char *cmd, int c, int *v)
{
	int	i;

	i = c;
	i++;
	while (cmd[i] != 34)
		i++;
	tmp->cmd[*v] = ft_substr(cmd, c + 1, i - (c + 1));
	*v = *v + 1;
	return (i + 1 - c);
}

int	single_quote(t_tmp *tmp, char *cmd, int c, int	*v)
{
	int	i;

	i = c;
	i++;
	while (cmd[i] != 39)
		i++;
	tmp->cmd[*v] = ft_substr(cmd, c + 1, i - (c + 1));
	*v = *v + 1;
	return (i + 1 - c);
}

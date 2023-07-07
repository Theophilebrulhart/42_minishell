/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:15:02 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/27 16:36:26 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	ft_write_echo(t_cmd *cmd, int i, int n)
{
	while (cmd->cmd_path[i])
	{
		printf("%s", cmd->cmd_path[i]);
		if (cmd->cmd_path[i + 1])
			printf(" ");
		i++;
	}
	if (n)
		printf("\n");
}

int	echo_n_check(t_cmd *cmd)
{
	int	i;

	i = 1;
	while (cmd->cmd_path[i])
	{
		if (cmd->cmd_path[i][0] != '-')
			return (i);
		if (!echo_all_n_check(cmd->cmd_path[i]))
			return (i);
		i++;
	}
	return (i);
}

int	echo_all_n_check(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n' && str[i] != 'e')
			return (0);
		i++;
	}
	return (1);
}

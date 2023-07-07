/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:09:47 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/28 14:10:16 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	unset_check(t_cmd *cmd, t_pipex *pipex, int j)
{
	int	i;

	i = 0;
	while (cmd->env[i])
	{
		if (!ft_strncmp_export(cmd->cmd_path[j], cmd->env[i]))
		{
			env_unset(cmd, pipex, i);
			break ;
		}
		i++;
	}
}

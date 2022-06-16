/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:30:46 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/13 15:09:06 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	is_builtin(t_cmd *cmd)
{
	(void)cmd;
	printf("is builtin ?\n");
	if (!ft_strncmp(cmd->cmd_path[0], "cd", ft_strlen(cmd->cmd_path[0])))
		printf("c'est le builtin cd\n");
	if (!ft_strncmp(cmd->cmd_path[0], "echo", ft_strlen(cmd->cmd_path[0])))
		printf("c'est le builtin echo\n");
	if (!ft_strncmp(cmd->cmd_path[0], "pwd", ft_strlen(cmd->cmd_path[0])))
		printf("c'est le builtin pwd\n");
	if (!ft_strncmp(cmd->cmd_path[0], "export", ft_strlen(cmd->cmd_path[0])))
		printf("c'est le builtin export\n");
	if (!ft_strncmp(cmd->cmd_path[0], "unset", ft_strlen(cmd->cmd_path[0])))
		printf("c'est le builtin unset\n");
	if (!ft_strncmp(cmd->cmd_path[0], "env", ft_strlen(cmd->cmd_path[0])))
		printf("c'est le builtin env\n");
	if (!ft_strncmp(cmd->cmd_path[0], "exit", ft_strlen(cmd->cmd_path[0])))
		printf("c'est le builtin exit\n");
	printf("fin de is builtin \n");
}

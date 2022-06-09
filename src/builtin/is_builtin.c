/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:30:46 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/09 17:52:10 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	is_builtin(t_cmd *cmd)
{
	(void)cmd;
	printf("is builtin ?\n");
	if (!ft_strncmp(cmd->cmd_path, "cd", ft_strlen(cmd->cmd_path)))
		printf("c'est le builtin cd\n");
	if (!ft_strncmp(cmd->cmd_path, "echo", ft_strlen(cmd->cmd_path)))
		printf("c'est le builtin echo\n");
	if (!ft_strncmp(cmd->cmd_path, "pwd", ft_strlen(cmd->cmd_path)))
		printf("c'est le builtin pwd\n");
	if (!ft_strncmp(cmd->cmd_path, "export", ft_strlen(cmd->cmd_path)))
		printf("c'est le builtin export\n");
	if (!ft_strncmp(cmd->cmd_path, "unset", ft_strlen(cmd->cmd_path)))
		printf("c'est le builtin unset\n");
	if (!ft_strncmp(cmd->cmd_path, "env", ft_strlen(cmd->cmd_path)))
		printf("c'est le builtin env\n");
	if (!ft_strncmp(cmd->cmd_path, "exit", ft_strlen(cmd->cmd_path)))
		printf("c'est le builtin exit\n");
}

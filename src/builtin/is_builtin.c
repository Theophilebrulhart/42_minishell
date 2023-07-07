/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:30:46 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/28 15:48:32 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	is_builtin(t_cmd *cmd, t_pipex *pipex, int id)
{
	if (!ft_strncmp(cmd->cmd_path[0], "cd", ft_strlen(cmd->cmd_path[0])))
		return (ft_cd(cmd, pipex, id));
	if (!ft_strncmp(cmd->cmd_path[0], "echo", ft_strlen(cmd->cmd_path[0])))
		return (ft_echo(cmd, pipex, id));
	if (!ft_strncmp(cmd->cmd_path[0], "pwd", ft_strlen(cmd->cmd_path[0])))
		return (ft_pwd(cmd, pipex, id));
	if (!ft_strncmp(cmd->cmd_path[0], "export", ft_strlen(cmd->cmd_path[0])))
		return (ft_export(cmd, pipex, id));
	if (!ft_strncmp(cmd->cmd_path[0], "unset", ft_strlen(cmd->cmd_path[0])))
		return (ft_unset(cmd, pipex, id));
	if (!ft_strncmp(cmd->cmd_path[0], "env", ft_strlen(cmd->cmd_path[0])))
		return (ft_env(cmd, pipex, id));
	if (!ft_strncmp(cmd->cmd_path[0], "exit", ft_strlen(cmd->cmd_path[0])))
		return (ft_exit(cmd, pipex, id));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:53:43 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/28 17:01:05 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	cd_redirection(t_cmd *cmd, t_pipex *pipex, int id)
{
	pipex->id_child = ft_realloc(pipex->id_child, 1, cmd, pipex);
	if (!pipex->id_child)
		free_all(pipex, cmd);
	pipex->id_child[id] = fork();
	close_cd_fd(cmd, pipex, id);
	if (pipex->id_child[id] < 0)
		free_all(pipex, cmd);
	if (pipex->id_child[id] == 0)
	{
		if (cmd->cmd_path[1] && chdir(cmd->cmd_path[1]) < 0)
		{
			printf("bash: cd: %s: No such file or directory\n",
				cmd->cmd_path[1]);
			g_return_status = 1;
			exit (1);
		}
		exit (0);
	}
}

void	get_new_oldpwd(t_cmd *cmd, t_pipex *pipex, char *pwd)
{
	int		i;
	int		j;
	char	*tmp_oldpwd;

	i = 0;
	tmp_oldpwd = NULL;
	while (cmd->env[++i])
	{
		if (!ft_strncmp(cmd->env[i], "OLDPWD", 5))
			break ;
	}
	tmp_oldpwd = cmd->env[i];
	if (!tmp_oldpwd)
	{
		i = 0;
		j = env_allocation(cmd, pipex, 1);
		cmd->env[j - 1] = ft_strjoin("OLDPWD=", pwd);
		cmd->env[j] = NULL;
		while (i < j)
			i++;
	}
	if (pwd && tmp_oldpwd)
		cmd->env[i] = ft_strjoin("OLDPWD=", pwd);
	else
		cmd->env[i] = NULL;
}

void	get_new_pwd(t_cmd *cmd, t_pipex *pipex)
{
	int		i;
	int		j;
	char	pwd[256];

	i = 0;
	j = 0;
	if (getcwd(pwd, sizeof(pwd)) == NULL)
		free_all(pipex, cmd);
	while (cmd->env[i])
	{
		if (!ft_strncmp(cmd->env[i], "PWD", 2))
		{
			cmd->env[i] = ft_strjoin("PWD=", pwd);
			return ;
		}
		i++;
	}
	i = 0;
	j = env_allocation(cmd, pipex, 1);
	cmd->env[j - 1] = ft_strjoin("PWD=", pwd);
	cmd->env[j] = NULL;
	while (i < j)
		i++;
}

void	go_to_home(t_cmd *cmd, t_pipex *pipex)
{
	int		i;
	int		t;
	char	pwd[256];

	i = 0;
	t = 0;
	if (getcwd(pwd, sizeof(pwd)) == NULL)
		free_all(pipex, cmd);
	i = 0;
	t = 0;
	while (pwd[i])
	{
		if (pwd[i] == '/')
			t++;
		i++;
	}
	while (t > 2)
	{
		chdir("..");
		t--;
	}
	get_new_pwd(cmd, pipex);
	get_new_oldpwd(cmd, pipex, pwd);
}

int	ft_cd( t_cmd *cmd, t_pipex *pipex, int id)
{
	char	pwd[256];

	if ((cmd->outfile != 0 && cmd->outfile > 0) || cmd->nbr_pipe)
	{
		cd_redirection(cmd, pipex, id);
		if (cmd->outfile <= 0)
			return (1);
	}
	if (cmd->cmd_path[1] == NULL || cmd->cmd_path[1][0] == '~')
		go_to_home(cmd, pipex);
	else
	{
		if (getcwd(pwd, sizeof(pwd)) == NULL)
			free_all(pipex, cmd);
		cd_go_to_dir(cmd, pipex);
		get_new_pwd(cmd, pipex);
		get_new_oldpwd(cmd, pipex, pwd);
	}
	g_return_status = 0;
	return (1);
}

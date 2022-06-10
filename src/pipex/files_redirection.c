/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:03:03 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/10 14:10:51 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../../includes/include.h"

void	infile_redirection(t_cmd *cmd, t_pipex *pipex, int *infile)
{
	*infile = open(cmd->infile, O_RDONLY, 0777);
	if (*infile == -1)
		error_exit(pipex, cmd, "no such file or directory", cmd->infile);
	dup2(*infile, STDIN_FILENO);
}

void	outfile_redirection(t_cmd *cmd, t_pipex *pipex, int *outfile)
{
	*outfile = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (*outfile == -1)
		error_exit(pipex, cmd, "zsh: cannot open : ", pipex->outfile);
	dup2(*outfile, STDOUT_FILENO);
}

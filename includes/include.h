/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:22 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/10 09:44:09 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"

typedef struct s_cmd {
	char	*infile;
	char	*outfile;
	char	**cmd_path;
	char	*full_cmd;
	char	**env;
	int		nbr_pipe;
}	t_cmd;

int		pipex_start(t_cmd *cmd);
void	ft_cd(char *path);
void	is_builtin(t_cmd *cmd);
#endif
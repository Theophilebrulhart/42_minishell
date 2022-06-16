/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:22 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/13 15:19:54 by theophilebr      ###   ########.fr       */
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
	int		infile_int;
	int		outfile_int;
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
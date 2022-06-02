/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:22 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/02 14:02:49 by theophilebr      ###   ########.fr       */
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

typedef struct	s_cmd
{
	int		infile;
	int		outfile;
	char	*cmd_path;
	char	*full_cmd;
}	t_cmd

int		pipex_start(int argc, char **argv, char **env);
void	ft_cd(char *path);
#endif
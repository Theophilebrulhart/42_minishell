/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:22 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/05/31 16:22:56 by tbrulhar         ###   ########.fr       */
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

int		pipex_start(int argc, char **argv, char **env);
void	ft_cd(char **env);
#endif
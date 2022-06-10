/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:15:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/10 11:25:36 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../includes/include.h"

typedef struct s_pipex {
	char		***cmd;
	int			*id_child;
	int			**fd_pipe;
	char		*infile;
	char		*outfile;
	char		**env;
	int			argc;
	char		**argv;
	int			nbr_pipe;
	char		*cmd_path;
}	t_pipex;

typedef struct s_env {
	int		i;
	int		j;
	int		t;
	char	*path;
	char	*path_str;
}	t_env;

char	***parsing_command(int argc, char **argv);
char	**ft_split(char const *s, char c);
void	first_child(t_pipex *pipex, t_cmd *cmd);
void	middle_child(t_pipex *pipex, t_cmd *cmd, int i);
void	last_child(t_pipex *pipex, t_cmd *cmd);
void	closing_middle_pipe(t_pipex *pipex, t_cmd *cmd, int id);
void	error_exit(t_pipex *pipex, t_cmd *cmd, char *err_message, char *prob);
void	free_all(t_pipex *pipex, t_cmd *cmd);
void	wait_all(t_pipex *pipex, t_cmd *cmd);
char	*parsing_command_path(t_pipex *pipex, t_cmd *cmd);
int		ft_strlen(const char *s);
char	*path_str(t_pipex *pipex, t_cmd *cmd);
char	*path_creation(t_pipex *pipex, char **all_path);
char	*access_test(t_pipex *pipex, t_cmd *cmd, char **all_path);
char	*ft_strjoin(char const *s1, char const *s2);
#endif

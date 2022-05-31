/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:15:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/05/31 16:01:08 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

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
	char		**cmd_path;
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
void	first_child(t_pipex *pipex);
void	middle_child(t_pipex *pipex, int i);
void	last_child(t_pipex *pipex);
void	closing_middle_pipe(t_pipex *pipex, int id);
void	error_exit(t_pipex *pipex, char *err_message, char *prob);
void	free_all(t_pipex *pipex);
void	wait_all(t_pipex *pipex);
char	**parsing_command_path(t_pipex *pipex);
int		ft_strlen(const char *s);
char	*path_str(t_pipex *pipex);
char	**path_creation(t_pipex *pipex, char **all_path);
char	*access_test(t_pipex *pipex, char **all_path, int cmd_nbr);
char	*ft_strjoin(char const *s1, char const *s2);
#endif

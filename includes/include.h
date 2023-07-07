/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:22 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/30 20:07:18 by pyammoun         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <termios.h>

int						g_return_status;

typedef struct s_cmd	t_cmd;
struct s_cmd {
	char			**cmd_path;
	int				infile;
	int				outfile;
	char			**env;
	int				nbr_pipe;
	int				status;
	t_cmd			*first;
	t_cmd			*next;
};

typedef struct s_info	t_info;
struct s_info {
	int				nb;	
	struct s_tmp	*tmp;	
	struct s_cmd	*cmd;
};

typedef struct s_tmp	t_tmp;
struct s_tmp {
	char			**cmd;	
	int				in;
	int				out;
	struct s_info	*info;
};

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
	int			nbr_id;
}	t_pipex;

typedef struct s_env {
	int		i;
	int		j;
	int		t;
	char	*path;
	char	*path_str;
}	t_env;

typedef struct s_utils {
	int		i;
	int		j;
	int		l;
	int		a;
	int		c;
	int		t;
}	t_utils;

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
char	*access_strjoin(char const *s1, char const *s2);
void	one_command_exec(t_pipex *pipex, t_cmd *cmd);
void	infile_redirection(t_cmd *cmd, t_pipex *pipex, int *infile);
void	outfile_redirection(t_cmd *cmd, t_pipex *pipex, int *outfile);
int		pipex_start(t_cmd *cmd);
int		ft_cd(t_cmd *cmd, t_pipex *pipex, int id);
int		is_builtin(t_cmd *cmd, t_pipex *pipex, int id);
void	printstruct(t_cmd *cmd);
void	splitinfo(t_info *info, t_cmd *cmd);
int		countingpipe(char *rlinput);
int		parsinginput(char *rlinput, t_cmd *cmd);
int		mainparsing(t_cmd *cmd);
t_cmd	*lstnew(t_cmd *cmd, t_tmp *tmp, int nb, t_cmd *first);
void	lstadd_back(t_cmd **alst, t_cmd *new);
t_cmd	*lstlast(t_cmd *list);
int		lstsize(t_cmd *lst);
void	printlst(t_cmd *lst);
int		env_allocation(t_cmd *cmd, t_pipex *pipex, int new);
int		**pipe_allocation(int nbr_pipe);
int		ft_export(t_cmd	*cmd, t_pipex *pipex, int id);
int		ft_exit(t_cmd *cmd, t_pipex *pipex, int id);
int		ft_unset(t_cmd *cmd, t_pipex *pipex, int id);
int		valid_identifier(t_cmd *cmd, int j);
int		ft_env(t_cmd *cmd, t_pipex *pipex, int id);
int		ft_echo(t_cmd *cmd, t_pipex *pipex, int id);
int		ft_pwd(t_cmd *cmd, t_pipex *pipex, int id);
int		*ft_realloc(int *str, int size, t_cmd *cmd, t_pipex *pipex);
char	*checkerforenv(char *tabinput, t_cmd *cmd);
int		checkend(char c);
char	*replaceenv(char *envtmp, int l, t_cmd *cmd);
int		indentifyspec(char *cmdargs, t_cmd *cmd);
char	**environnementalloc(t_cmd *cmd);
_Bool	evenquote(char *line);
int		uperlowerunder(char c);
void	printabinput(char **tabi, int nb);
int		ft_strncmp_export(const char *s1, const char *s2);
void	ft_str_is_num(t_cmd *cmd, char *str);
void	close_parent_fd(t_pipex *pipex, t_cmd *cmd);
int		already_exist(t_cmd *cmd, int j);
void	error_exit(t_pipex *pipex, t_cmd *cmd, char *err_message, char *prob);
void	export_redirection(t_cmd *cmd, t_pipex *pipex, int id, int i);
int		export_special_arg(t_cmd *cmd, t_pipex *pipex, int j);
int		export_without_arg(t_cmd *cmd, t_pipex *pipex);
void	builtin_fd(t_cmd *cmd, t_pipex *pipex, int id);
void	areyouin(char c, t_utils *utl);
void	endodd(char **tab, t_cmd *cmd);
void	ft_append(t_tmp *tmp, char *file);
void	checkredirection(t_cmd *cmd);
char	*getfile2(char *line, int c);
char	*getfile1(char *line, int c);
int		value_check(char *str);
void	env_unset(t_cmd *cmd, t_pipex *pipex, int unset);
int		ft_strncmp_unset(const char *s1, const char *s2);
int		checkredirerror(char *line, char c, int n);
int		promptchecker(char *line, t_cmd *cmd);
_Bool	spacechecker(char *line);
int		endspace(char *line);
int		starter_separation(char *line, t_cmd *cmd);
int		sep_count(char const *s, char c);
char	**ft_splitu(char const *s, char c);
int		ft_sep_countu(char const *s, char c);
int		redirechoose(t_tmp *tmp, char *cmd, int i, t_info *info);
void	struct_setter(t_tmp *tmp, char *cmd, t_info *info);
int		find_space(char *line, int c);
int		single_quote(t_tmp *tmp, char *cmd, int c, int *v);
int		dobble_quote(t_tmp *tmp, char *cmd, int c, int *v);
char	*ft_strjoinu(char const *s1, char const *s2);
int		find_spacu(char *line, int c);
void	ft_write_echo(t_cmd *cmd, int i, int n);
void	cd_go_to_dir(t_cmd *cmd, t_pipex *pipex);
void	areyouin2(char c, t_utils *utl);
int		cmd_counter(char *cmd);
int		env_var_exist(t_cmd *cmd, char *str);
int		not_valid_identifier(t_cmd *cmd, t_pipex *pipex, int i);
void	error_infile(t_tmp *tmp, char *file, t_info *info, char *cmd);
void	error_export(t_info *info);
int		echo_n_check(t_cmd *cmd);
int		echo_all_n_check(char *str);
int		ft_strncmp_env(char **env, char *s);
void	setup_struct2(t_utils *utl);
void	unset_check(t_cmd *cmd, t_pipex *pipex, int j);
int		export_arg(t_cmd *cmd, t_pipex *pipex, int i);
void	close_cd_fd(t_cmd *cmd, t_pipex *pipex, int id);
void	ft_signal(void);
void	sig_int(int n);
void	sig_quit(int n);
void	unset_parent_signals(void);
void	set_child_signals(void);

#endif

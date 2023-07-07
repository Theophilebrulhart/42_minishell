/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:46:56 by pyammoun          #+#    #+#             */
/*   Updated: 2022/10/30 20:29:08 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	sig_int(int n)
{
	if (n == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_return_status = 128 + SIGINT;
	}
}

void	splitinfo(t_info *info, t_cmd *cmd)
{
	int		i;
	t_cmd	*first;

	i = 0;
	info->nb -= 1;
	while (i <= info->nb)
	{
		if (i == 0)
		{
			first = lstnew(cmd, &info->tmp[i], info->nb, first);
			cmd->first = first;
			cmd->first->env = environnementalloc(cmd);
		}
		else
			lstadd_back((&cmd->first),
				lstnew(cmd, &info->tmp[i], info->nb, cmd->first));
		i++;
	}
	pipex_start(cmd->first);
}

int	parsinginput(char *rlinput, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (rlinput[0] == 0)
		mainparsing(cmd);
	if (!promptchecker(rlinput, cmd))
		mainparsing(cmd);
	return (0);
}

int	mainparsing(t_cmd *cmd)
{
	char			*rlinput;
	struct termios	save;
	struct termios	curr;

	tcgetattr(STDIN_FILENO, &curr);
	tcgetattr(STDIN_FILENO, &save);
	curr.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, 0, &curr);
	signal(SIGINT, sig_int);
	signal(SIGQUIT, SIG_IGN);
	rlinput = readline("Prompt:");
	if (rlinput == 0)
		exit(0);
	if (rlinput[0] != '\0')
		add_history(rlinput);
	parsinginput(rlinput, cmd);
	tcsetattr(STDIN_FILENO, 0, &save);
	return (0);
}

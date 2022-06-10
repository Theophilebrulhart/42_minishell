/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:25:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/10 11:43:22 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	main(int argc, char **argv, char **env)
{
	t_cmd	cmd;

	cmd.cmd_path = malloc(3 * sizeof(*cmd.cmd_path));
	cmd.cmd_path[0] = argv[2];
	cmd.cmd_path[1] = argv[3];
	cmd.cmd_path[2] = NULL;
	cmd.infile = NULL;
	cmd.outfile = argv[4];
	printf("cmd.outfile : %s\n", cmd.outfile);
	cmd.env = env;
	cmd.nbr_pipe = 2;
	pipex_start(&cmd);
	(void)argc;
	(void)argv;
	(void)env;
	return (0);
}

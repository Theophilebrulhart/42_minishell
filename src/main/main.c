/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:25:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/13 16:57:57 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"
#include "../pipex/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_cmd	cmd;

	cmd.cmd_path = malloc(3 * sizeof(*cmd.cmd_path));
	cmd.cmd_path[0] = argv[2];
	cmd.cmd_path[1] = argv[3];
	cmd.cmd_path[2] = NULL;
	cmd.infile = argv[1];
	cmd.outfile = NULL;
	cmd.infile_int = open(cmd.infile, O_RDONLY, 0777);
	if (cmd.infile_int== -1)
		printf("open infile raté\n");
	cmd.outfile_int = open(cmd.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (cmd.outfile_int == -1)
		printf("open outfil raté");
	printf("cmd.outfile : %s\n", cmd.outfile);
	cmd.env = env;
	cmd.nbr_pipe = 2;
	pipex_start(&cmd);
	(void)argc;
	(void)argv;
	(void)env;
	return (0);
}

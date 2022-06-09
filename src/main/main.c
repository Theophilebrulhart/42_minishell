/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:25:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/09 20:09:51 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	main(int argc, char **argv, char **env)
{
	t_cmd	cmd;

	cmd.cmd_path[0] = argv[2];
	cmd.infile = argv[1];
	cmd.outfile = argv[4];
	cmd.env = env;
	cmd.nbr_pipe = argv[3][0];
	pipex_start(&cmd);
	(void)argc;
	(void)argv;
	(void)env;
	return (0);
}

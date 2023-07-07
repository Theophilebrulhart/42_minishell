/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:25:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/13 15:41:49 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	main(int argc, char **argv, char **env)
{
	t_cmd	cmd;

	g_return_status = 0;
	(void)argc;
	(void)argv;
	if (argc != 1)
		return (0);
	cmd.env = env;
	cmd.status = 0;
	mainparsing(&cmd);
	printf("main return 0\n");
	return (0);
}

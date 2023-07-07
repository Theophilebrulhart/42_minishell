/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:29:05 by pyammoun          #+#    #+#             */
/*   Updated: 2022/10/25 17:29:09 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	error_infile(t_tmp *tmp, char *file, t_info *info, char *cmd)
{
	free (info->tmp);
	free (cmd);
	free (file);
	(void)tmp;
	printf("error\n");
	mainparsing(info->cmd);
}

void	error_export(t_info *info)
{
	free (info->tmp);
	mainparsing(info->cmd);
}

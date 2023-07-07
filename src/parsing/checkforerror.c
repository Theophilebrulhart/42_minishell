/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkforerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <pyammoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:45:55 by pyammoun          #+#    #+#             */
/*   Updated: 2022/07/13 18:27:05 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	setup_struct(t_utils *var)
{
	var->i = -1;
	var->l = 0;
	var->a = 0;
}

_Bool	evenquote(char *line)
{
	t_utils	var;

	setup_struct(&var);
	while (line[++var.i])
	{
		if (line[var.i] == '"' && var.a != 1)
		{
			if (var.l == 1)
				var.l = 0;
			else
				var.l = 1;
		}
		if (line[var.i] == 39 && var.l != 1)
		{
			if (var.a == 1)
				var.a = 0;
			else
				var.a = 1;
		}		
	}
	if (var.l == 1 || var.a == 1)
		return (true);
	else
		return (false);
}

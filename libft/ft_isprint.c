/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:37:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/10/27 15:05:34 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	if (ft_isprint(argv[1][0]))
		printf("is printable");
	else
		printf("is non-printable");
	return (0);
}*/

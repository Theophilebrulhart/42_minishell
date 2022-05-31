/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:17:35 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/10/27 15:05:35 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int main(int argc, char** argv)
{
    (void)argc;
    if (ft_isascii(argv[1][0]))
        printf("is ascii");
    else
        printf("is non-ascii");
    return (0);
}*/
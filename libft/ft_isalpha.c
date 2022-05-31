/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:35:16 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/10/27 15:05:36 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

/*int main(int argc, char** argv)
{
    (void)argc;
    if(ft_isalpha(argv[1][0]))
        printf("is alpha");
    else
        printf("is non-alpha");
    return (0);
}*/
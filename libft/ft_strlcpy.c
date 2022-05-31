/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:33:59 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/11 13:48:30 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/*int	main(int argc, char **argv)
{
	int	size;

	size = 6;
	(void)argc;
	printf("\ndest avant : %s\n", argv[1]);
	printf("longeur src : %zu\n", ft_strlcpy(argv[1], argv[2], size));
	printf("dest apres : %s\n", argv[1]);
	printf("\nofficiel longeur src : %zu\n", strlcpy(argv[1], argv[2], size));
	printf("officiel dest apres : %s\n\n", argv[1]);
}*/

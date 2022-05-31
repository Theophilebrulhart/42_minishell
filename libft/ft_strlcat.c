/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:57:48 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/11 13:48:20 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	if (size > i)
	{
		while (src[j] && size > 0 && i < size - 1)
			dest[i++] = src[j++];
		dest[i] = '\0';
		while (src[j++])
			i++;
		return (i);
	}
	while (src[j])
		j++;
	return (size + j);
}

/*int	main(void)
{
	size_t	size;
	char moi[30] = "1 2 3 4 5 6 7 8 9 ";
	char officiel[30] = "1 2 3 4 5 6 7 8 9 ";
	const char src[] = "AAAAAAAAA";

	size = -1;
	printf("\nlongeur : %lu\n", ft_strlcat(moi, src, size));
	printf("apres concat : %s\n", moi);
	printf("\nofficiel\n");
	printf("longeur : %lu\n", strlcat(officiel, src, size));
	printf("apres concat : %s\n", officiel);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:25:01 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/08 12:58:03 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] && i < size)
	{
		j = 0;
		while (s1[j + i] == s2[j] && (j + i) < size)
		{	
			if (s2[j + 1] == '\0')
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_strnstr(argv[1], argv[2], argv[3][0]));
	printf("officiel : %s\n", strnstr(argv[1], argv[2], argv[3][0]));
}*/

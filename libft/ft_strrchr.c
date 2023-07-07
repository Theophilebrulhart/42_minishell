/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:28:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/05 15:23:47 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	while (i >= 0)
	{
		if (*str == (char)c)
			return ((char *)str);
		str--;
		i--;
	}
	str = NULL;
	return ((char *)str);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_strrchr(argv[1], argv[2][0] + 256));
	printf("officiel : %s", strrchr(argv[1], argv[2][0] + 256));
	return (0);
}*/

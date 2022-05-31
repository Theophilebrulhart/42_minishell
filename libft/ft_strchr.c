/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:48:43 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/05 15:36:51 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c && *str)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	else
		str = NULL;
	return ((char *)str);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_strchr(argv[1], argv[2][0]));
	printf("%s", ft_strchr(argv[1], 't' + 256));
	return (0);
}*/

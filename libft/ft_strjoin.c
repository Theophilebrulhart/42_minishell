/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:26:58 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/17 18:35:12 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return ((char *)s2);
	while (s1[i])
			i++;
	while (s2[j])
		j++;
	str = malloc((i + j) * sizeof(*str) + 1);
	if (str == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_strjoin(argv[1], argv[2]));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:54:01 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/03 16:20:06 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	is_set(char const *s, char const *set, int i)
{
	int	j;

	j = 0;
	while (s[i] != set[j] && set[j])
		j++;
	if (s[i] == set[j])
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		stocki;

	i = 0;
	j = 0;
	while (is_set(s, set, i) && s[i])
		i++;
	stocki = i;
	while (s[i])
		i++;
	i--;
	while (is_set(s, set, i) && i > stocki)
		i--;
	str = malloc((i - stocki) * sizeof(*str) + 2);
	if (!str)
		return (str);
	j = 0;
	while (stocki <= i)
		str[j++] = s[stocki++];
	str[j] = '\0';
	return (str);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_strtrim(argv[1], argv[2]));
	return (0);
}*/

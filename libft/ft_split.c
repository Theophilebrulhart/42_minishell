/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:06:09 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/28 17:03:45 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*create_dup(char const *s, char c, int j, int i)
{
	char	*dup;

	dup = malloc(j * sizeof(*dup) + 1);
	if (!dup)
		return (dup);
	j = 0;
	while (s[i] != c && s[i])
	{
		dup[j] = s[i];
		i++;
		j++;
	}
	dup[j] = '\0';
	return (dup);
}

int	ft_sep_count(char const *s, char c)
{
	int		i;
	int		sep_count;

	i = 0;
	sep_count = 0;
	if (s[0] != c && s[0] != 0)
		sep_count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			sep_count++;
		i++;
	}
	return (sep_count);
}

void	filling_word(int sep_count, const char *s, char **tab, char c)
{
	int	t;
	int	j;
	int	i;

	t = 0;
	j = 0;
	i = 0;
	while (t < sep_count)
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + j] != c && s[i + j])
			j++;
		tab[t++] = create_dup(s, c, j, i);
		i += j;
	}
	tab[t] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		sep_count;

	sep_count = ft_sep_count(s, c);
	tab = malloc((sep_count + 1) * sizeof(*tab));
	if (!s)
		return (tab);
	if (!tab)
		return (tab);
	filling_word(sep_count, s, tab, c);
	return (tab);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	printf("%p\n", ft_split(argv[1], argv[2][0])[0]);
	printf("%s\n", ft_split(argv[1], argv[2][0])[1]);
	//printf("%s\n", ft_split(argv[1], argv[2][0])[2]);
	//printf("%s\n", *ft_split("-salut--ca-va-", '-'));
	return (0);
}*/

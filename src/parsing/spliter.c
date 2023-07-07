/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:33:23 by pyammoun          #+#    #+#             */
/*   Updated: 2022/10/28 13:33:24 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

char	*create_dupu(char const *s, char c, int j, int i)
{
	char	*dup;
	int		v;

	(void)c;
	dup = malloc(j * sizeof(*dup) + 1);
	if (!dup)
		return (dup);
	v = i + j;
	j = 0;
	while (i < v && s[i])
	{
		dup[j] = s[i];
		i++;
		j++;
	}
	dup[j] = '\0';
	return (dup);
}

int	ft_sep_countu(char const *s, char c)
{
	int		i;
	int		sep_count;

	i = -1;
	sep_count = 0;
	if (s[0] != c && s[0] != 0)
		sep_count++;
	while (s[++i])
	{
		if (s[i] == 34)
		{
			i++;
			while (s[i] != 34)
				i++;
		}
		if (s[i] == 39)
		{
			i++;
			while (s[i] != 39)
				i++;
		}
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			sep_count++;
	}
	return (sep_count);
}

void	help_spliter(const char *s, int *i, int *j, char c)
{
	*j = 0;
	while (s[*i] == c && s[*i])
		(*i)++;
	while (s[*i + *j] != c && s[*i + *j])
	{
		if (s[*i + *j] == 34)
		{
			(*j)++;
			while (s[*i + *j] != 34)
				(*j)++;
		}
		else if (s[*i + *j] == 39)
		{
			(*j)++;
			while (s[*i + *j] != 39)
				(*j)++;
		}
		(*j)++;
	}
}

void	filling_wordu(int sep_count, const char *s, char **tab, char c)
{
	int	t;
	int	j;
	int	i;

	t = 0;
	j = 0;
	i = 0;
	while (t < sep_count)
	{
		help_spliter(s, &i, &j, c);
		tab[t++] = create_dupu(s, c, j, i);
		i += j;
	}
	tab[t] = 0;
}

char	**ft_splitu(char const *s, char c)
{
	char	**tab;
	int		sep_count;

	sep_count = ft_sep_countu(s, c);
	tab = malloc((sep_count + 1) * sizeof(*tab));
	if (!s)
		return (tab);
	if (!tab)
		return (tab);
	filling_wordu(sep_count, s, tab, c);
	return (tab);
}

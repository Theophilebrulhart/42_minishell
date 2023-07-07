/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:07:03 by pyammoun          #+#    #+#             */
/*   Updated: 2022/10/30 20:06:41 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

char	*ft_strndup(char *src, int len)
{
	int		i;
	char	*strcopie;

	i = 0;
	while (src[i] && i < len)
		i++;
	strcopie = malloc(i * sizeof(*strcopie) + 1);
	if (strcopie == NULL)
		return (strcopie);
	i = 0;
	while (src[i] && i < len)
	{
		strcopie[i] = src[i];
		i++;
	}
	strcopie[i] = '\0';
	return (strcopie);
}

char	*ft_strjoinu(char const *s1, char const *s2)
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
	str = malloc((i + j + 2) * sizeof(*str));
	if (str == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	str[i++] = ' ';
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

void	unset_parent_signals(void)
{
	signal(SIGINT, SIG_IGN);
	g_return_status = 128 + SIGINT;
}

void	set_child_signals(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	g_return_status = 128 + SIGINT;
}

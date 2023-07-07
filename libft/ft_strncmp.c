/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:37:33 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/10/30 20:35:33 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (1);
	while (*s1 && *s2 && *s1 == *s2 && i < (size))
	{
		s1++;
		s2++;
		i++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/*int main (void)
{
	int	size = 4;
	char str1[] = "0123";
	char str2[] = "012.";
	int retour = 0;

	int a = 2;
	printf("%i \n", ft_strncmp("", "", a));
	printf(">%i \n", strncmp("", "", a));
	printf("%i \n", ft_strncmp("123", "123", a));
	printf(">%i \n", strncmp("123", "123", a));
	printf("%i \n", ft_strncmp("123", "124", a));
	printf(">%i \n", strncmp("123", "124", a));
	printf("%i \n", ft_strncmp("124", "1", a));
	printf(">%i \n", strncmp("124", "1", a));
	printf("%i \n", ft_strncmp("124323412", "ppp", a));
	printf(">%i \n", strncmp("124323412", "ppp", a));
	printf("%i \n", ft_strncmp("eaf", "asdf", a));
	printf(">%i \n", strncmp("eaf", "asdf", a));
	printf("%i \n", ft_strncmp("11111", "11111", a));
	printf(">%i \n", strncmp("11111", "11111", a));
	printf("%i \n", ft_strncmp("1", "1", a));
	printf(">%i \n", strncmp("1", "1", a));

	retour = ft_strncmp(str1, str2, size);
	printf("%d\n", retour);
	printf("%d\n", strncmp(str1, str2, size));
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:59:24 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/10/27 15:05:38 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && n != 0)
	{
		((unsigned char *)str)[i] = '\0';
		i++;
	}
}

/*int main()
{
	char str[] = "salut";
	size_t n = 4;
	int i = 0;
	ft_bzero(str, n);
	while (i < 6)
	{
		printf("%c", str[i]);
		i++;
	}
	return (0);
}*/
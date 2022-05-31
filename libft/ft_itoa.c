/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:29:39 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/10 12:22:56 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static char	*allocation(int n)
{
	int		i;
	char	*str;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	str = malloc(i * sizeof(*str) + 1);
	if (!str)
		return (str);
	str[i * sizeof(*str)] = '\0';
	return (str);
}

static void	conversion(int n, char *str, int i)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		str[i++] = '-';
		if (n < -9)
			conversion((n / 10), str, i);
	}
	str[i++] = '0' + (n % 10) * sign;
	if (n > 9)
		conversion((n / 10), str, i);
}

static void	swap(char *str, int i)
{
	char	stock;
	int		j;

	j = 0;
	if (str[i] == '-')
		i++;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		stock = str[i];
		str[i] = str[j];
		str[j] = stock;
		j--;
		i++;
	}		
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = allocation(n);
	if (!str)
		return (str);
	conversion(n, str, i);
	swap(str, i);
	return (str);
}

/*int	main(void)
{
	printf("%s\n", ft_itoa(-58595));
	return (0);
}*/

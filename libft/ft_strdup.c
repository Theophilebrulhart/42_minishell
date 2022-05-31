/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:33:57 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/08 13:08:55 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*strcopie;

	i = 0;
	while (src[i])
		i++;
	strcopie = malloc(i * sizeof(*strcopie) + 1);
	if (strcopie == NULL)
		return (strcopie);
	i = 0;
	while (src[i])
	{
		strcopie[i] = src[i];
		i++;
	}
	strcopie[i] = '\0';
	return (strcopie);
}

/*int	main(int argc, char *argv[])
{
	char	*verif;

	(void)argc;
	verif = ft_strdup(argv[1]);
	printf("\nmoi : %s\n", ft_strdup(argv[1]));
	printf("\nofficiel : %s\n", strdup(argv[1]));
}*/

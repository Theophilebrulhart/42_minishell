/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:26:23 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/11 14:00:30 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > (size_t)ft_strlen(s))
		str = malloc((ft_strlen(s) + 1) * sizeof(*str));
	else
		str = malloc((len + 1) * sizeof(*str));
	if (!str)
		return (str);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && s[i] && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

/*int	main(void)
{
	printf("%s\n", ft_substr("tripouille", 0, 42000));
	return (0);
}*/

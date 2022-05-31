/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:16:30 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/08 11:29:48 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*(unsigned char *)str == (unsigned char)c)
			return ((unsigned char *)str);
		str++;
		i++;
	}
	return (NULL);
}

/*int main() {

    char data[] = {0, 1, 2 , 3, 4, 5};
    const unsigned int size = 1;
	int nbr = 0;

    // On recherche une valeur inhéxistante :
    void * found = ft_memchr( data, 57, size );
    printf( "57 is %s\n", ( found != NULL ? "found" : "not found" ) );
    if ( found != NULL ) {
        printf( "La valeur à la position calculée est %d\n", *((char *) found) );
    }

    // On recherche une valeur existante :
    found = ft_memchr( data, nbr, size );
    printf( "%d is %s\n", nbr, ( found != NULL ? "found" : "not found" ) );
    if ( found != NULL ) {
        printf( "La valeur à la position calculée est %d\n", *((char *) found) );
    }

    return (0);
}*/
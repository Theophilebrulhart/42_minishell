/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:19:06 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/04 13:09:49 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <assert.h>

void	*ft_calloc(size_t nbrelem, size_t sizeelem)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nbrelem * sizeelem);
	if (ptr == NULL)
		return (ptr);
	while (i < (nbrelem * sizeelem) && (nbrelem * sizeelem) != 0)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

/*int main() {
    
    int i;
    int * pointer = (int *) calloc( INT_NUMBER, sizeof(int) );


    assert( pointer != NULL );

    for ( i=0; i<INT_NUMBER-1; i++ ) {
        pointer[i] = i;
    }

    for (i=0; i<INT_NUMBER; i++ ) {
        printf( "%d ", pointer[i] );
    }
    printf( "\n" );


    free( pointer );

    return 0;
}*/
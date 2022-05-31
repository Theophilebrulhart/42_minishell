/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:46:01 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/08 14:10:11 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*str;

	dest = (unsigned char *)dst;
	str = (unsigned char *)src;
	i = 0;
	if (!dest && !str)
		return (NULL);
	if (str < dest)
		while (++i <= len)
			dest[len - i] = str[len - i];
	else
		while (len-- > 0)
			*(dest++) = *(str++);
	return (dst);
}

/*int main() {

    // On crée une zone de mémoire de 10 entiers et contenant
    // que neuf valeurs. La dixième est non utilisée (0).
    int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };

    // On affiche le contenu de la collection
    for( int i=0; i< 10; i++ ) {
        printf( "%d ", data[i] );
    }
    puts( "" );  // Un retour à la ligne

    // On décale les éléménts dans la collection ...
    void *source = (void *) data;
    void *destination = (void *) ( data + 1 );
    ft_memmove( destination, source, 4 );

    // ... pour y insérer une nouvelle valeur en tête
    data[0] = 10;

    // On affiche le contenu de la collection
    for( int i=0; i<ELEMENT_COUNT; i++ ) {
        printf( "%d ", data[i] );
    }
    puts( "" );  // Un retour à la ligne

    return EXIT_SUCCESS;
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:02:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/11 13:47:47 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((uintptr_t)src != (uintptr_t)dst)
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/*int	main()
{
	int	array [] = { 54, 85, 20, 63, 21 };
	int	*copy = NULL;
	int	length = sizeof( int ) * 5;
	
	copy = (int *) malloc( length );
	ft_memcpy( copy, array, length );
		
	
	for( length=0; length<5; length++ ) {
		printf( "%d ", copy[ length ] );
	}
	printf( "\n" );
		
	free( copy );

	return EXIT_SUCCESS;
}*/
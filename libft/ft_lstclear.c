/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:37:55 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/10 14:58:31 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del) (void*))
{
	t_list	*tmp;

	if (*lst)
	{
		while (*lst)
		{
			tmp = (*lst)-> next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
	}
}

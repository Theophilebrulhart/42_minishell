/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:01:40 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/10 14:58:51 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*stock;

	if (!lst || !f || !del)
		return (0);
	new_list = ft_lstnew(f(lst -> content));
	if (!new_list)
		return (0);
	stock = new_list;
	lst = lst -> next;
	while (lst)
	{
		new_list -> next = ft_lstnew(f(lst -> content));
		if (!new_list -> next)
		{
			ft_lstclear(&stock, del);
			return (0);
		}
		new_list = new_list -> next;
		lst = lst -> next;
	}
	new_list -> next = NULL;
	return (stock);
}

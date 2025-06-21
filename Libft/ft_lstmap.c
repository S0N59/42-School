/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:55:31 by nkostany          #+#    #+#             */
/*   Updated: 2023/01/24 10:09:40 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*node1;

	if (!f || !del)
		return (0);
	node1 = 0;
	while (lst)
	{
		node = ft_lstnew((*f)(lst -> content));
		if (!node)
		{
			while (node1)
			{
				node = node1 -> next;
				(*del)(node1 -> content);
				free(node1);
				node1 = node;
			}
			lst = 0;
			return (0);
		}
		ft_lstadd_back (&node1, node);
		lst = lst -> next;
	}
	return (node1);
}

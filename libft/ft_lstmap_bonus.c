/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:17:01 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/24 23:44:31 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Iterates the list lst and applies the function f on the content of each
 * node. Creates a new list resulting of the successive applications of the 
 * function f. The del function is used to delete the content of
 * a node if needed.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*initial;

	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	if (!new_list)
		return (NULL);
	initial = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew((*f)(lst->content));
		if (!new_list)
		{
			ft_lstclear(&initial, del);
			return (NULL);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	return (initial);
}

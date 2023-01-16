/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:10:04 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/24 23:32:13 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Deletes and frees the given node and every successor of that node,
 * using the function del and free.
 * Finally, the pointer to the list must be set to NULL.
 */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*next;

	if (lst && *lst)
	{
		elem = *lst;
		while (elem)
		{
			next = elem->next;
			ft_lstdelone(elem, *del);
			elem = next;
		}
		*lst = NULL;
	}
}

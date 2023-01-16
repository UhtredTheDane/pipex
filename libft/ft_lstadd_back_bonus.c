/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:58:09 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/24 23:33:43 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Adds the node new at the end of the list.
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			elem = *lst;
			while (elem->next)
				elem = elem->next;
			elem->next = new;
		}
	}
}

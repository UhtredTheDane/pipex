/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:45:00 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/21 15:55:36 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Returns the last node of the list.
 */

t_list	*ft_lstlast(t_list *lst)
{	
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

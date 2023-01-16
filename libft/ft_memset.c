/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:05:26 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/19 16:07:33 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *Description:
 *
 * Fills the first n bytes of the memory area pointed to by s 
 * with the constant byte c.
 */

void	*ft_memset(void *s, int c, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char *)s;
	while (i < n)
	{
		*(temp + i) = c;
		i++;
	}
	return (temp);
}

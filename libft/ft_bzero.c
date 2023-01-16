/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:41:21 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/29 14:16:01 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Erases the data in the n bytes of the memory starting at the location 
 * pointed to by s, by writing zeros (bytes containing '\0') to that area.
 */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_char;
	size_t			i;

	s_char = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		*(s_char + i) = '\0';
		i++;
	}
}

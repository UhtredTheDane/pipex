/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:16:12 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/19 16:18:35 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Scans the initial n bytes of the memory area pointed to by s for 
 * the first instance of c.
 * Both c and the bytes of the memory area po
 *
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;

	char_s = (unsigned char *)s;
	while (n--)
	{
		if (*char_s == (unsigned char) c)
			return (char_s);
		char_s++;
	}
	return (NULL);
}

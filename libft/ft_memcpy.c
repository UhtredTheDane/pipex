/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:07:45 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/25 00:08:13 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *Description:
 *
 * Copies n bytes from memory area src to memory area dest.
 * The memory areas must not overlap.
 */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*char_dest;
	char	*char_src;
	size_t	i;

	char_dest = (char *)dest;
	char_src = (char *)src;
	i = 0;
	if (char_dest || char_src)
	{
		while (i < n)
		{
			*(char_dest + i) = *(char_src + i);
			i++;
		}
	}
	return (dest);
}

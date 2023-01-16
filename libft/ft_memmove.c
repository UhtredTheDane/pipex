/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:13:12 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/22 12:26:10 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Copies n bytes from memory area src to memory area dest.
 * The memory areas may overlap.
 * Without temporary array.
 */

static void	copy(char *char_dest, char *char_src, size_t n)
{
	size_t	i;

	if (char_dest >= char_src)
	{
		i = n - 1;
		while ((int)i >= 0)
		{
			*(char_dest + i) = *(char_src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(char_dest + i) = *(char_src + i);
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	copy((char *)dest, (char *)src, n);
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:23:44 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/19 16:25:33 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 * 
 * Appends the NUL-terminated string src to the end of dst.
 * It will append at most size - strlen(dst) - 1 bytes,
 * NUL-terminating the result.
 */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_length;
	size_t	src_length;
	char	*initial_dst;

	i = size;
	initial_dst = dst;
	while (i != 0 && *dst != '\0')
	{
		dst++;
		i--;
	}
	src_length = ft_strlen(src);
	if (i == 0)
		return (src_length + size);
	dst_length = dst - initial_dst;
	while (i - 1 != 0 && *src != '\0')
	{
		*(dst++) = *(src++);
		i--;
	}	
	*(dst++) = '\0';
	return (dst_length + src_length);
}

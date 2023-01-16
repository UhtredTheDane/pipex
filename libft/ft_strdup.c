/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:59:12 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/19 17:00:48 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Allocates sufficient memory for a copy of the string s, 
 * does the copy and returns a pointer to it.
 */

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(s);
	dst = malloc(sizeof(char) * (src_len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(dst + i) = *(s + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

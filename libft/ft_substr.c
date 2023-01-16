/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:29:21 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/01 11:43:48 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *Description:
 *
 * Allocates and returns a substring from the string 's'.
 * The substring begins at index 'start' and is of maximum size 'len'.
 *
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
		len = 0;
	else if (len >= len_s)
		len = len_s - start;
	sub_string = malloc(sizeof(char) * (len + 1));
	if (!sub_string)
		return (NULL);
	if (len > 0)
		ft_strlcpy(sub_string, s + start, len + 1);
	else
		*sub_string = '\0';
	return (sub_string);
}

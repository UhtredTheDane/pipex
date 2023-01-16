/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:59:21 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/24 18:31:54 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Description:
 * 
 * Allocates and returns a copy of s1 with the characters specified in set 
 * removed from the beginning and the end of the string.
 */

static size_t	get_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) && ft_strchr(set, *(s1 + i)))
		i++;
	return (i);
}

static size_t	get_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_strchr(set, *(s1 + i)))
		i--;
	if (i < 0)
		return (0);
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	start;
	size_t	end;
	size_t	size_s;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start <= end && *(s1 + end))
		size_s = end - start + 1;
	else
		size_s = 0;
	s = malloc(sizeof(char) * (size_s + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1 + start, size_s + 1);
	return (s);
}

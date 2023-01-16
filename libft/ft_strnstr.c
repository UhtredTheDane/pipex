/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:30:31 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/24 22:32:04 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Locates the first occurrence of the null-terminated string little 
 * in the string big,
 * where not more than len characters are searched.
 *
 */

static char	*find_str(const char *big, const char *little, size_t len,
	size_t len_b)
{
	size_t	i;
	size_t	j;
	size_t	i_start;
	size_t	len_l;

	i = 0;
	len_l = ft_strlen(little);
	while (len_b - i >= len_l && i < len)
	{
		j = 0;
		i_start = i;
		if (*(big + i) == *(little + j))
		{
			while (*(big + i) == *(little + j) && *(big + i)
				&& *(little + j++))
				if (i < len)
					i++;
			if (i - i_start == len_l)
				return ((char *)big + i_start);
			i = i_start;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_big;

	if (*little == '\0')
		return ((char *)big);
	len_big = ft_strlen(big);
	return (find_str(big, little, len, len_big));
}

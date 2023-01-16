/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:46:58 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/22 12:28:26 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Applies the function f to each character of the string s,
 * and passing its index as first argument to create a new string resulting
 * from successive applications of f.
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	s_len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	res = malloc(sizeof(char) * (s_len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(res + i) = (*f)(i, *(s + i));
		i++;
	}
	*(res + i) = '\0';
	return (res);
}

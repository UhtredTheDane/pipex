/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:28:06 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/23 16:36:49 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Compare not more than n bytes from the array pointed to by s1 to the array 
 * pointed to by s2.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_bis;
	unsigned char	*s2_bis;

	if (n == 0)
		return (0);
	i = 0;
	s1_bis = (unsigned char *)s1;
	s2_bis = (unsigned char *)s2;
	while (i < n - 1 && *(s1_bis + i) && *(s2_bis + i))
	{
		if (*(s1_bis + i) != *(s2_bis + i))
			return (*(s1_bis + i) - *(s2_bis + i));
		i++;
	}
	return (*(s1_bis + i) - *(s2_bis + i));
}	

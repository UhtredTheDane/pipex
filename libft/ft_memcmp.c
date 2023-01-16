/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:18:49 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/19 16:20:20 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Compares the first n bytes (each interpreted as unsigned char) 
 * of the memory areas s1 and s2.
 *
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_bis;
	unsigned char	*s2_bis;

	s1_bis = (unsigned char *)s1;
	s2_bis = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_bis != *s2_bis)
			return (*s1_bis - *s2_bis);
		s1_bis++;
		s2_bis++;
	}
	return (0);
}

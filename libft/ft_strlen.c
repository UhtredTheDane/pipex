/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:43:09 by alexis            #+#    #+#             */
/*   Updated: 2022/07/23 14:56:48 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *Description:
 *
 * Calculates the length of the string pointed to by s, 
 * excluding the terminating null byte.
 */

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*(s + length))
		length++;
	return (length);
}

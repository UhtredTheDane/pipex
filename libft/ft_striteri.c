/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:10:09 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/19 22:48:18 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Applies the function f on each character of the string passed as argument,
 * passing its index as first argument. Each character is passed by adresse to f
 * to be modified if necessary.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (s && f)
	{
		i = 0;
		while (*(s + i))
		{
			(*f)(i, s + i);
			i++;
		}
	}
}

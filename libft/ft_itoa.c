/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:01:35 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/22 22:26:56 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Allocates and returns a string representing the integer received as an 
 * argmument.
 * Negative numbers must be handled.
 */

static size_t	count_numbers(int n)
{
	size_t	res;

	if (n == 0)
		return (1);
	res = 0;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static char	*make_string(int n, int negatif)
{
	char	*res;
	int		i;
	int		reste;
	size_t	size;

	size = count_numbers(n) + negatif;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = size;
	res[i] = '\0';
	while (--i >= 0 + negatif)
	{
		reste = n % 10;
		if (negatif)
			reste *= -1;
		res[i] = reste + '0';
		n /= 10;
	}
	if (negatif)
		res[i] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	int	negatif;

	if (n < 0)
		negatif = 1;
	else
		negatif = 0;
	return (make_string(n, negatif));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:56:45 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/30 15:30:05 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
 * Description:
 *
 * Allocates space for nmemb objects, each size bytes in length.
 * The allocated memory is explicitly initialized to zero bytes.
 */

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*emplacement;
	size_t	i;
	size_t	max;

	max = SIZE_MAX;
	if (size && max / size < nmemb)
		return (NULL);
	emplacement = malloc(nmemb * size);
	if (!emplacement)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		*(emplacement + i) = '\0';
		i++;
	}
	if (size * nmemb == 0)
		emplacement[0] = '\0';
	return ((void *) emplacement);
}

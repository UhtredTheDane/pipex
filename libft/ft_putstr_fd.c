/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:12:43 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/24 23:26:07 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Outputs the string s to the given file descriptor.
 */

void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd >= 0)
		while (*s)
			ft_putchar_fd(*(s++), fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 05:41:35 by alexis            #+#    #+#             */
/*   Updated: 2022/07/19 05:42:14 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *Description:
 * 
 * Checks wheter c is 7-bit unsigned char value that fits 
 * into the ASCII character set.
 */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

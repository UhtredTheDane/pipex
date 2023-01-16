/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:31:20 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/24 23:27:18 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	show_number(int n, int fd)
{
	int	reste;

	if (n != 0)
	{
		reste = n % 10;
		show_number(n / 10, fd);
		ft_putchar_fd(reste + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n == 0)
			ft_putchar_fd('0', fd);
		else if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else if (n < 0)
		{
			n *= -1;
			ft_putchar_fd('-', fd);
			show_number(n, fd);
		}
		else
			show_number(n, fd);
	}
}

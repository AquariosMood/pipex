/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:32:04 by crios             #+#    #+#             */
/*   Updated: 2024/09/17 15:48:18 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdarg.h>

void	ft_puthex_min(unsigned int nbr, int fd)
{
	if (nbr >= 16)
	{
		ft_puthex_min(nbr / 16, fd);
		ft_puthex_min(nbr % 16, fd);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', fd);
		else
			ft_putchar_fd(nbr - 10 + 'a', fd);
	}
}

int	print_hex_min(va_list args)
{
	unsigned int	x;
	unsigned int	temp;
	int				len;

	x = va_arg(args, unsigned int);
	len = 0;
	temp = x;
	if (temp == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while (temp > 0)
	{
		len++;
		temp /= 16;
	}
	ft_puthex_min(x, 1);
	return (len);
}

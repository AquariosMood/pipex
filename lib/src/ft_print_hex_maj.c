/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:32:13 by crios             #+#    #+#             */
/*   Updated: 2024/09/17 15:48:20 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdarg.h>

void	ft_puthex_maj(unsigned int nbr, int fd)
{
	if (nbr >= 16)
	{
		ft_puthex_maj(nbr / 16, fd);
		ft_puthex_maj(nbr % 16, fd);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', fd);
		else
			ft_putchar_fd(nbr - 10 + 'A', fd);
	}
}

int	print_hex_maj(va_list args)
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
	ft_puthex_maj(x, 1);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:32:26 by crios             #+#    #+#             */
/*   Updated: 2024/09/17 15:45:53 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdarg.h>
#include <stdint.h>

void	ft_putnbr_base_fd(unsigned long nbr, char *base, int fd)
{
	unsigned long	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
	{
		ft_putnbr_base_fd(nbr / base_len, base, fd);
		ft_putnbr_base_fd(nbr % base_len, base, fd);
	}
	else
		ft_putchar_fd(base[nbr], fd);
}

int	handle_null(void)
{
	ft_putstr_fd("(nil)", 1);
	return (5);
}

int	print_memory(va_list args)
{
	uintptr_t	ptr;
	uintptr_t	temp_ptr;
	int			len;
	int			digits;

	ptr = (uintptr_t)va_arg(args, void *);
	temp_ptr = ptr;
	len = 0;
	if (ptr == 0)
		return (handle_null());
	digits = 0;
	ft_putstr_fd("0x", 1);
	len += 2;
	while (temp_ptr > 0)
	{
		digits++;
		temp_ptr /= 16;
	}
	ft_putnbr_base_fd(ptr, "0123456789abcdef", 1);
	len += digits;
	return (len);
}

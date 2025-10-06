/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:12:23 by crios             #+#    #+#             */
/*   Updated: 2024/09/17 15:46:15 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	find_format(const char *format, va_list args, int *len)
{
	if (format[0] == 'c')
		*len += print_char(args);
	else if (format[0] == 's')
		*len += print_string(args);
	else if (format[0] == 'p')
		*len += print_memory(args);
	else if (format[0] == 'd' || format[0] == 'i')
		*len += print_int(args);
	else if (format[0] == 'u')
		*len += print_unsigned_int(args);
	else if (format[0] == 'x')
		*len += print_hex_min(args);
	else if (format[0] == 'X')
		*len += print_hex_maj(args);
	else if (format[0] == '%')
	{
		ft_putchar_fd('%', 1);
		(*len)++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		len;

	va_start(args, format);
	count = 0;
	len = 0;
	while (format[count])
	{
		if (format[count] == '%')
		{
			count++;
			find_format(&format[count], args, &len);
		}
		else
		{
			ft_putchar_fd(format[count], 1);
			len++;
		}
		count++;
	}
	va_end(args);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:31:44 by crios             #+#    #+#             */
/*   Updated: 2024/09/17 15:46:00 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

int	is_int_min(char *buffer)
{
	ft_memcpy(buffer, "-2147483648", 11);
	return (0);
}

int	is_negative(char *buffer, int n, int *is_neg)
{
	int	temp;
	int	i;

	i = 0;
	if (n == INT_MIN)
		return (is_int_min(buffer));
	if (n < 0)
	{
		buffer[0] = '-';
		*is_neg = 1;
		temp = -n;
		i = 1;
	}
	else
		temp = n;
	while (temp)
	{
		buffer[i++] = '0' + (temp % 10);
		temp /= 10;
	}
	if (n == 0)
		buffer[i++] = '0';
	buffer[i] = '\0';
	return (i);
}

void	int_to_string(char *buffer, int n)
{
	int		i;
	int		is_neg;
	int		start;
	int		end;
	char	swap;

	is_neg = 0;
	ft_memset(buffer, 0, 13);
	i = is_negative(buffer, n, &is_neg);
	if (n == 0)
		return ;
	if (is_neg)
		start = 1;
	else
		start = 0;
	end = i - 1;
	while (start < end)
	{
		swap = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = swap;
		start++;
		end--;
	}
}

int	print_int(va_list args)
{
	int		n;
	char	buffer[13];
	int		len;
	char	*ptr;

	len = 0;
	n = va_arg(args, int);
	int_to_string(buffer, n);
	ptr = buffer;
	while (*ptr)
	{
		ft_putchar_fd(*ptr, 1);
		ptr++;
		len++;
	}
	return (len);
}

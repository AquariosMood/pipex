/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:48:41 by crios             #+#    #+#             */
/*   Updated: 2024/09/17 15:48:25 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;

	if (dest == NULL && src == NULL)
		return (dest);
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (a > b)
	{
		while (len)
		{
			a[len - 1] = b[len - 1];
			len--;
		}
	}
	else
	{
		while (len--)
			*a++ = *b++;
	}
	return (dest);
}

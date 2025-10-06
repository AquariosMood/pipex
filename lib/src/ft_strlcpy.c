/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:54:45 by crios             #+#    #+#             */
/*   Updated: 2024/05/20 13:42:39 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < destsize)
	{
		*dest++ = *src++;
		++i;
	}
	if (i < destsize)
		*dest = 0;
	while (*src++)
		++i;
	return (i);
}

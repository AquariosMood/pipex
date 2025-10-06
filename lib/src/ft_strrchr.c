/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:16:49 by crios             #+#    #+#             */
/*   Updated: 2024/09/17 15:47:22 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;

	ret = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ret = s;
		++s;
	}
	if (*s == (char)c)
		return ((char *)s);
	if (c == '\0' && ret == s)
		return ((char *)s);
	return ((char *)ret);
}

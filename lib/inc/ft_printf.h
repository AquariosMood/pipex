/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crios <crios@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:31:47 by crios             #+#    #+#             */
/*   Updated: 2024/10/07 15:23:57 by crios            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		print_char(va_list args);
int		print_hex_maj(va_list arg);
int		print_hex_min(va_list arg);
int		print_int(va_list args);
int		print_memory(va_list arg);
int		print_string(va_list args);
int		print_unsigned_int(va_list args);
void	ft_puthex(unsigned int n, int uppercase);

#endif

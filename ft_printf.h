/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:03:07 by wleite            #+#    #+#             */
/*   Updated: 2021/10/07 23:48:32 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NULL_PATTERN "____[0x0]"
# define PERCENT_PATTERN "____[0x25]"

# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*parse_flags(const char *format, va_list *ap);
int		print_to_fd(const char *format, int fd);

size_t	is_decimal(char type);
char	*replace_decimal(char *format, int value);

size_t	is_integer(char type);
char	*replace_integer(char *format, int value);

size_t	is_string(char type);
char	*replace_string(char *format, char *value);

size_t	is_char(char type);
char	*replace_char(char *format, int value);

size_t	is_percent(char type);
char	*replace_percent(char *format);

size_t	is_u_int(char type);
char	*replace_u_int(char *format, unsigned int value);

size_t	is_u_hex(char type);
char	*replace_u_hex(char *format, char type, unsigned int value);

size_t	is_pointer(char type);
char	*replace_pointer(char *format, unsigned long int value);

#endif

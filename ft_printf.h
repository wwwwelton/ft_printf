/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:03:07 by wleite            #+#    #+#             */
/*   Updated: 2021/10/09 16:06:00 by wleite           ###   ########.fr       */
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

char	*replace_decimal(char *format, int value);
char	*replace_integer(char *format, int value);
char	*replace_string(char *format, char *value);
char	*replace_char(char *format, int value);
char	*replace_percent(char *format);
char	*replace_u_int(char *format, unsigned int value);
char	*replace_u_hex(char *format, char type, unsigned int value);
char	*replace_pointer(char *format, unsigned long int value);

#endif

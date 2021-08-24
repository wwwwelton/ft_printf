/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:03:07 by wleite            #+#    #+#             */
/*   Updated: 2021/08/23 22:21:04 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FD 1

# define NULL_PATTERN "____[0x0]"
# define PERCENT_PATTERN "____[0x25]"

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	free_ptr(char **ptr);
char	*str_replace(const char *str, char *old_word, char *new_word);
char	*ft_replace_flags(const char *format, va_list *ap);
int		ft_print_parser_fd(const char *format);

void	ft_strrev(char *str);

size_t	is_decimal(const char *format);
char	*replace_decimal(char *format, int value);

size_t	is_string(const char *format);
char	*replace_string(char *format, char *value);

size_t	is_char(const char *format);
char	*replace_char(char *format, int value);

size_t	is_percent(const char *format);
char	*replace_percent(char *format);

size_t	is_uinteger(const char *format);
char	*replace_uinteger(char *format, unsigned int value);

#endif

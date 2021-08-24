/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:03:07 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 18:18:39 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FD 1
# define NULL_PATTERN "____[0x0]"
# define PERCENT_PATTERN "____[0x25]"

# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	free_ptr(char **ptr);
char	*str_replace(const char *str, char *old_word, char *new_word);
char	*ft_replace_flags(const char *format, va_list *ap);
int		ft_print_parser_fd(const char *format);

char	*ft_char_tostr(char c);

void	ft_strrev(char *str);
void	ft_str_toupper(char *str);

size_t	is_decimal(char type);
char	*replace_decimal(char *format, char type, int value);

size_t	is_ch_dec_int(char type);
char	*replace_ch_dec_int(char *format, char type, int value);
size_t	is_u_int_hex(char type);
char	*replace_u_int_hex(char *format, char type, unsigned int value);

size_t	is_string(char type);
char	*replace_string(char *format, char *value);

size_t	is_char(char type);
char	*replace_char(char *format, int value);

size_t	is_percent(char type);
char	*replace_percent(char *format);

size_t	is_uinteger(char type);
char	*replace_uinteger(char *format, unsigned int value);

size_t	is_u_hexadecimal(char type);
char	*replace_u_hexadecimal(char *format, char type, int value);

size_t	is_pointer(char type);
char	*replace_pointer(char *format, unsigned long int value);

#endif

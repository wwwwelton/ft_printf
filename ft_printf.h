/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:03:07 by wleite            #+#    #+#             */
/*   Updated: 2021/10/13 00:33:16 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NULL_PATTERN "____[0x0]"
# define PERCENT_PATTERN "____[0x25]"

# define FD 1

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_args
{
	int		negative;
	int		hash;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	char	type;
	char	*argument;
}	t_args;

char	*parse_args(const char *format, va_list *ap);
char	*replace_char(char *format, int value, t_args *args);
char	*replace_decimal(char *format, int value, t_args *args);
char	*replace_integer(char *format, int value, t_args *args);
char	*replace_percent(char *format);
char	*replace_pointer(char *format, unsigned long int value, t_args *args);
char	*replace_string(char *format, char *value, t_args *args);
char	*replace_u_hex(char *format, unsigned int value, t_args *args);
char	*replace_u_int(char *format, unsigned int value, t_args *args);
int		get_args(t_args *args, const char *format, va_list *ap);
int		print_to_fd(const char *format, int fd);
void	deinit_args(t_args *args);
void	init_args(t_args *args);

/**
 * @brief Sends formatted output to stdout.
 *
 * @param format This is the null-terminated string (C-string)
 * that is written to stdout. It consists of characters along with
 * optional format specifiers starting with %. Format tags prototype is
 * %[flags][width][.precision]specifier.
 * @param ... Depending on the format string, other additional
 * arguments specifying the data to be printed.
 * They occur in a sequence according to the format specifier.
 * @return The total number of characters written is returned.
 */
int		ft_printf(const char *format, ...);

#endif

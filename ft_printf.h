/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:03:07 by wleite            #+#    #+#             */
/*   Updated: 2021/10/12 06:17:43 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NULL_PATTERN "____[0x0]"
# define PERCENT_PATTERN "____[0x25]"

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_args
{
	int		negative;
	int		hash;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		len;
	int		width;
	int		dot;
	int		precision;
	char	type;
	char	*argument;
}	t_args;

int		ft_printf(const char *format, ...);
char	*parse_args(const char *format, va_list *ap);
int		print_to_fd(const char *format, int fd);

void	init_args(t_args *args);
void	deinit_args(t_args *args);

int		get_args(t_args *args, const char *format, va_list *ap);

char	*replace_decimal(char *format, int value, t_args *args);
char	*replace_integer(char *format, int value, t_args *args);
char	*replace_string(char *format, char *value, t_args *args);
char	*replace_char(char *format, int value, t_args *args);
char	*replace_percent(char *format);
char	*replace_u_int(char *format, unsigned int value);
char	*replace_u_hex(char *format, char type, unsigned int value);
char	*replace_pointer(char *format, unsigned long int value, t_args *args);

void	debug(t_args *args);

char	*ft_char_to_str(char c, size_t len);

char	*ft_strmerge(char *s1, char *s2);

#endif

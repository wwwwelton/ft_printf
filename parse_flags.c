/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 02:24:09 by wleite            #+#    #+#             */
/*   Updated: 2021/10/09 03:15:53 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*replace_flags(char flag, char *fmt, va_list *ap)
{
	if (is_string(flag))
		fmt = replace_string(fmt, va_arg(*ap, char *));
	else if (is_pointer(flag))
		fmt = replace_pointer(fmt, va_arg(*ap, unsigned long int));
	else if (is_char(flag))
		fmt = replace_char(fmt, va_arg(*ap, int));
	else if (is_decimal(flag))
		fmt = replace_decimal(fmt, va_arg(*ap, int));
	else if (is_integer(flag))
		fmt = replace_integer(fmt, va_arg(*ap, int));
	else if (is_u_int(flag))
		fmt = replace_u_int(fmt, va_arg(*ap, unsigned int));
	else if (is_u_hex(flag))
		fmt = replace_u_hex(fmt, flag, va_arg(*ap, unsigned int));
	else if (is_percent(flag))
		fmt = replace_percent(fmt);
	return (fmt);
}

char	*parse_flags(const char *format, va_list *ap)
{
	char	*fmt;

	fmt = ft_strdup(format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			fmt = replace_flags(*format, fmt, ap);
		}
		format++;
	}
	return (fmt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:02:58 by wleite            #+#    #+#             */
/*   Updated: 2021/08/22 01:33:59 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*fmt;
	int		fmt_len;

	va_start(ap, format);
	fmt = ft_strdup(format);
	while (*format)
	{
		if (is_char(format))
			fmt = replace_char(fmt, va_arg(ap, int));
		else if (is_string(format))
			fmt = replace_string(fmt, va_arg(ap, char *));
		else if (is_decimal(format))
			fmt = replace_decimal(fmt, va_arg(ap, int));
		else if (is_percent(format))
			fmt = replace_percent(fmt);
		format++;
	}
	va_end(ap);
	fmt_len = ft_strlen(fmt);
	write(1, fmt, fmt_len);
	free_ptr(&fmt);
	return (fmt_len);
}

/*
while (fmt[i] != '\0')
	{
		//c
		if (is_char(&fmt[i]))
			fmt = replace_char(fmt, va_arg(ap, int));
		//s
		else if (is_string(&fmt[i]))
			fmt = replace_string(fmt, va_arg(ap, char *));
		//p
		// else if (is_pointer(&fmt[i]))
		// 	fmt = replace_pointer(fmt, va_arg(ap, int));
		//d | i
		else if (is_decimal(&fmt[i]))
			fmt = replace_decimal(fmt, va_arg(ap, int));
		// //u
		// else if (is_unsigned_int(&fmt[i]))
		// 	fmt = replace_unsigned_int(fmt, va_arg(ap, int));
		// //x | X
		// else if (is_hexa_decimal(&fmt[i]))
		// 	fmt = replace_hexa_decimal(fmt, va_arg(ap, int));
		// //%%
		// else if (is_mod(&fmt[i]))
		// 	fmt = replace_mod(fmt, va_arg(ap, int));
		else
			i++;
	}
*/

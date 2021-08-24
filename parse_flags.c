/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 02:24:09 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 19:44:54 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_flags(const char *format, va_list *ap)
{
	char	*fmt;

	fmt = ft_strdup(format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (is_string(*format))
				fmt = replace_string(fmt, va_arg(*ap, char *));
			else if (is_pointer(*format))
				fmt = replace_pointer(fmt, va_arg(*ap, unsigned long int));
			else if (is_ch_dec_int(*format))
				fmt = parse_ch_dec_int(fmt, *format, va_arg(*ap, int));
			else if (is_u_int_hex(*format))
				fmt = parse_u_int_hex(fmt, *format, va_arg(*ap, unsigned int));
			else if (is_percent(*format))
				fmt = replace_percent(fmt);
		}
		format++;
	}
	return (fmt);
}

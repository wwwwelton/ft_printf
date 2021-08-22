/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 02:24:09 by wleite            #+#    #+#             */
/*   Updated: 2021/08/22 05:22:52 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_replace_type(const char *format, va_list *ap)
{
	char	*fmt;

	fmt = ft_strdup(format);
	while (*format)
	{
		if (is_char(format))
			fmt = replace_char(fmt, va_arg(*ap, int));
		else if (is_string(format))
			fmt = replace_string(fmt, va_arg(*ap, char *));
		else if (is_decimal(format))
			fmt = replace_decimal(fmt, va_arg(*ap, int));
		else if (is_percent(format))
			fmt = replace_percent(fmt);
		format++;
	}
	return (fmt);
}

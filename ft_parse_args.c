/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 02:24:09 by wleite            #+#    #+#             */
/*   Updated: 2021/10/10 01:13:04 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*parse_types(char type, char *fmt, va_list *ap, t_args *args)
{
	(void)args;
	if (type == 's')
		fmt = replace_string(fmt, va_arg(*ap, char *));
	else if (type == 'p')
		fmt = replace_pointer(fmt, va_arg(*ap, unsigned long int));
	else if (type == 'c')
		fmt = replace_char(fmt, va_arg(*ap, int));
	else if (type == 'd')
		fmt = replace_decimal(fmt, va_arg(*ap, int));
	else if (type == 'i')
		fmt = replace_integer(fmt, va_arg(*ap, int));
	else if (type == 'u')
		fmt = replace_u_int(fmt, va_arg(*ap, unsigned int));
	else if (type == 'x' || type == 'X')
		fmt = replace_u_hex(fmt, type, va_arg(*ap, unsigned int));
	else if (type == '%')
		fmt = replace_percent(fmt);
	return (fmt);
}

char	*parse_args(const char *format, va_list *ap)
{
	char	*fmt;
	size_t	size;
	t_args	args;

	fmt = ft_strdup(format);
	size = ft_strlen(format);
	while (*format)
	{
		if (*format == '%')
		{
			init_args(&args, size);
			format += get_args(&args, format, ap);
			fmt = parse_types(*format, fmt, ap, &args);
			deinit_args(&args);
		}
		format++;
	}
	return (fmt);
}

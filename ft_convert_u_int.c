/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:24:16 by wleite            #+#    #+#             */
/*   Updated: 2021/10/13 10:17:24 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_width(char *uinteger, t_args *args)
{
	char	padding;
	char	*width;

	if (args->zero && args->precision != 0 && !args->dot)
		padding = '0';
	else
		padding = ' ';
	args->width -= ft_strlen(uinteger);
	if (args->width > -1)
	{
		width = ft_char_to_str(padding, args->width);
		if (args->minus)
			uinteger = ft_strmerge(uinteger, width);
		else
			uinteger = ft_strmerge(width, uinteger);
	}
	return (uinteger);
}

static char	*apply_precision(char *uinteger, unsigned int value, t_args *args)
{
	char	*precision;

	if (value == 0 && args->precision <= 0 && args->dot)
	{
		ft_free_ptr((void *)&uinteger);
		return (ft_strdup(""));
	}
	args->precision -= ft_strlen(uinteger);
	if (args->precision > -1)
	{
		precision = ft_char_to_str('0', args->precision);
		uinteger = ft_strmerge(precision, uinteger);
	}
	return (uinteger);
}

char	*replace_u_int(char *format, unsigned int value, t_args *args)
{
	char	*uinteger;

	uinteger = ft_uitoa_base(value, "0123456789");
	uinteger = apply_precision(uinteger, value, args);
	uinteger = apply_width(uinteger, args);
	format = ft_str_replace(format, args->argument, uinteger);
	ft_free_ptr((void *)&uinteger);
	return (format);
}

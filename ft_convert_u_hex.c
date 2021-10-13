/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/10/13 10:17:54 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_flags(char *hexadecimal, unsigned int value, t_args *args)
{
	if (args->hash && value)
		hexadecimal = ft_strmerge(ft_strdup("0x"), hexadecimal);
	return (hexadecimal);
}

static char	*apply_width(char *hexadecimal, t_args *args)
{
	char	padding;
	char	*width;

	if (args->zero && args->precision != 0 && !args->dot)
		padding = '0';
	else
		padding = ' ';
	args->width -= ft_strlen(hexadecimal);
	if (args->width > -1)
	{
		width = ft_char_to_str(padding, args->width);
		if (args->minus)
			hexadecimal = ft_strmerge(hexadecimal, width);
		else
			hexadecimal = ft_strmerge(width, hexadecimal);
	}
	return (hexadecimal);
}

static char	*apply_precision(char *hexadecimal, unsigned value, t_args *args)
{
	char	*precision;

	if (value == 0 && args->precision <= 0 && args->dot)
	{
		ft_free_ptr((void *)&hexadecimal);
		return (ft_strdup(""));
	}
	args->precision -= ft_strlen(hexadecimal);
	if (args->precision > -1)
	{
		precision = ft_char_to_str('0', args->precision);
		hexadecimal = ft_strmerge(precision, hexadecimal);
	}
	return (hexadecimal);
}

char	*replace_u_hex(char *format, unsigned int value, t_args *args)
{
	char	*hexadecimal;

	hexadecimal = ft_uitoa_base(value, "0123456789abcdef");
	hexadecimal = apply_precision(hexadecimal, value, args);
	hexadecimal = apply_width(hexadecimal, args);
	hexadecimal = apply_flags(hexadecimal, value, args);
	if (args->type == 'X')
		ft_str_toupper(hexadecimal);
	format = ft_str_replace(format, args->argument, hexadecimal);
	ft_free_ptr((void *)&hexadecimal);
	return (format);
}

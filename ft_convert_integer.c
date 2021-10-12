/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/10/12 09:57:47 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*delete_minus(char *integer, t_args *args)
{
	char	*tmp;

	if (*integer == '-')
	{
		tmp = ft_substr(integer, 1, ft_strlen(integer));
		args->negative = 1;
		ft_free_ptr((void *)&integer);
		return (tmp);
	}
	return (integer);
}

static char	*apply_flags(char *integer, t_args *args)
{
	if (args->plus && !args->negative)
		integer = ft_strmerge(ft_strdup("+"), integer);
	else if (args->space && !args->negative)
		integer = ft_strmerge(ft_strdup(" "), integer);
	return (integer);
}

static char	*apply_width(char *integer, t_args *args)
{
	char	padding;
	char	*width;

	if (args->zero && args->precision != 0 && !args->dot)
	{
		integer = delete_minus(integer, args);
		padding = '0';
	}
	else
		padding = ' ';
	if (args->negative && padding == ' ')
		args->width -= ft_strlen(integer);
	else
		args->width -= ft_strlen(integer) + args->negative;
	if (args->width > -1)
	{
		width = ft_char_to_str(padding, args->width);
		if (args->minus)
			integer = ft_strmerge(integer, width);
		else
			integer = ft_strmerge(width, integer);
	}
	if (args->negative && padding != ' ')
		integer = ft_strmerge(ft_strdup("-"), integer);
	return (integer);
}

static char	*apply_precision(char *integer, int value, t_args *args)
{
	char	*precision;

	if (args->precision == 0 && value == 0)
	{
		ft_free_ptr((void *)&integer);
		return (ft_strdup(""));
	}
	if (value < 0)
		integer = delete_minus(integer, args);
	args->precision -= ft_strlen(integer);
	if (args->precision > -1)
	{
		precision = ft_char_to_str('0', args->precision);
		integer = ft_strmerge(precision, integer);
	}
	if (args->negative)
		integer = ft_strmerge(ft_strdup("-"), integer);
	return (integer);
}

char	*replace_integer(char *format, int value, t_args *args)
{
	char	*integer;

	integer = ft_itoa(value);
	integer = apply_precision(integer, value, args);
	integer = apply_width(integer, args);
	integer = apply_flags(integer, args);
	format = ft_str_replace(format, args->argument, integer);
	ft_free_ptr((void *)&integer);
	return (format);
}

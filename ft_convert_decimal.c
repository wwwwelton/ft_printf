/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/10/10 10:56:12 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*delete_minus(char *decimal, t_args *args)
{
	char	*tmp;

	if (*decimal == '-')
	{
		tmp = ft_substr(decimal, 1, ft_strlen(decimal));
		args->negative = 1;
		ft_free_ptr((void *)&decimal);
		return (tmp);
	}
	return (decimal);
}

static char	*apply_flags(char *decimal, t_args *args)
{
	if (args->plus && !args->negative)
		decimal = ft_strmerge(ft_strdup("+"), decimal);
	else if (args->space && !args->negative)
		decimal = ft_strmerge(ft_strdup(" "), decimal);
	return (decimal);
}

static char	*apply_width(char *decimal, t_args *args)
{
	char	padding;
	char	*width;

	if (args->zero && *decimal != '\0' && args->precision <= 0)
	{
		decimal = delete_minus(decimal, args);
		padding = '0';
	}
	else
		padding = ' ';
	if (args->negative && padding == ' ')
		args->width -= ft_strlen(decimal);
	else
		args->width -= ft_strlen(decimal) + args->negative;
	if (args->width > -1)
	{
		width = ft_char_to_str(padding, args->width);
		if (args->minus)
			decimal = ft_strmerge(decimal, width);
		else
			decimal = ft_strmerge(width, decimal);
	}
	if (args->negative && padding != ' ')
		decimal = ft_strmerge(ft_strdup("-"), decimal);
	return (decimal);
}

static char	*apply_precision(char *decimal, t_args *args)
{
	char	*precision;

	if (args->precision == 0 && *decimal == '0')
	{
		ft_free_ptr((void *)&decimal);
		return (ft_strdup(""));
	}
	if (*decimal == '-')
		decimal = delete_minus(decimal, args);
	args->precision -= ft_strlen(decimal);
	if (args->precision > -1)
	{
		precision = ft_char_to_str('0', args->precision);
		decimal = ft_strmerge(precision, decimal);
	}
	if (args->negative)
		decimal = ft_strmerge(ft_strdup("-"), decimal);
	return (decimal);
}

char	*replace_decimal(char *format, int value, t_args *args)
{
	char	*decimal;

	decimal = ft_itoa(value);
	decimal = apply_precision(decimal, args);
	decimal = apply_width(decimal, args);
	decimal = apply_flags(decimal, args);
	format = ft_str_replace(format, args->argument, decimal);
	ft_free_ptr((void *)&decimal);
	return (format);
}

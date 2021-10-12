/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 02:24:09 by wleite            #+#    #+#             */
/*   Updated: 2021/10/11 09:39:05 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_flags(t_args *args, const char *format)
{
	while (1)
	{
		if (format[args->i] == '#')
			args->hash = 1;
		else if (format[args->i] == '-')
			args->minus = 1;
		else if (format[args->i] == '+')
			args->plus = 1;
		else if (format[args->i] == ' ')
			args->space = 1;
		else if (format[args->i] == '0')
			args->zero = 1;
		else
			break ;
		args->argument[args->j++] = format[args->i];
		args->i++;
	}
}

static void	get_width(t_args *args, const char *format, va_list *ap)
{
	if (ft_isdigit(format[args->i]))
	{
		while (ft_isdigit(format[args->i]))
		{
			args->width = (args->width * 10) + (format[args->i] - '0');
			args->argument[args->j++] = format[args->i];
			args->i++;
		}
	}
	else if (format[args->i] == '*')
	{
		args->width = va_arg(*ap, int);
		if (args->width < 0)
		{
			args->minus = 1;
			args->width = -args->width;
		}
		args->argument[args->j++] = '*';
		args->i++;
	}
}

static void	get_precision(t_args *args, const char *format, va_list *ap)
{
	if (format[args->i] == '.')
	{
		args->argument[args->j++] = '.';
		args->dot = 1;
		args->precision = 0;
		args->i++;
		if (ft_isdigit(format[args->i]))
		{
			while (ft_isdigit(format[args->i]))
			{
				args->precision = (args->precision * 10)
					+ (format[args->i] - '0');
				args->argument[args->j++] = format[args->i];
				args->i++;
			}
		}
		else if (format[args->i] == '*')
		{
			args->precision = va_arg(*ap, int);
			args->argument[args->j++] = '*';
			args->i++;
		}
	}
}

int	get_args(t_args *args, const char *format, va_list *ap)
{
	args->argument[args->j++] = format[args->i++];
	get_flags(args, format);
	get_width(args, format, ap);
	get_precision(args, format, ap);
	args->argument[args->j++] = format[args->i];
	args->type = format[args->i];
	args->len = args->i + 1;
	return (args->i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 02:24:09 by wleite            #+#    #+#             */
/*   Updated: 2021/10/12 11:04:02 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_flags(t_args *args, const char **format)
{
	while (1)
	{
		if (*(*format) == '#')
			args->hash = 1;
		else if (*(*format) == '-')
			args->minus = 1;
		else if (*(*format) == '+')
			args->plus = 1;
		else if (*(*format) == ' ')
			args->space = 1;
		else if (*(*format) == '0')
			args->zero = 1;
		else
			break ;
		*args->argument++ = *(*format)++;
	}
}

static void	get_width(t_args *args, const char **format, va_list *ap)
{
	if (ft_isdigit(**format))
	{
		while (ft_isdigit(**format))
		{
			args->width = (args->width * 10) + (**format - '0');
			*args->argument++ = *(*format)++;
		}
	}
	else if (**format == '*')
	{
		args->width = va_arg(*ap, int);
		if (args->width < 0)
		{
			args->minus = 1;
			args->width = -args->width;
		}
		*args->argument++ = '*';
	}
}

static void	get_precision(t_args *args, const char **format, va_list *ap)
{
	if (**format == '.')
	{
		*args->argument++ = *(*format)++;
		args->dot = 1;
		args->precision = 0;
		if (ft_isdigit(**format))
		{
			while (ft_isdigit(**format))
			{
				args->precision = (args->precision * 10) + (**format - '0');
				*args->argument++ = *(*format)++;
			}
		}
		else if (**format == '*')
		{
			args->precision = va_arg(*ap, int);
			*args->argument++ = '*';
		}
	}
}

int	get_args(t_args *args, const char *format, va_list *ap)
{
	char	*old_address;

	args->argument = ft_calloc(ft_strlen(format) + 1, sizeof(char));
	old_address = args->argument;
	*args->argument++ = *format++;
	get_flags(args, &format);
	get_width(args, &format, ap);
	get_precision(args, &format, ap);
	*args->argument = *format;
	args->type = *format;
	args->argument = old_address;
	return (ft_strlen(args->argument) - 1);
}

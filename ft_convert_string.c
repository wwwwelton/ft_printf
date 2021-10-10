/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/10/10 03:26:35 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_precision(char *string, t_args *args)
{
	char	*tmp;

	if (args->precision > -1)
	{
		tmp = ft_substr(string, 0, args->precision);
		ft_free_ptr((void *)&string);
		return (tmp);
	}
	return (string);
}

static char	*apply_width(char *string, t_args *args)
{
	char	*tmp;
	char	*width;

	args->width -= ft_strlen(string);
	if (args->width > 0)
	{
		width = ft_char_to_str(' ', args->width);
		if (args->minus)
			tmp = ft_strjoin(string, width);
		else
			tmp = ft_strjoin(width, string);
		ft_free_ptr((void *)&string);
		ft_free_ptr((void *)&width);
		return (tmp);
	}
	return (string);
}

char	*replace_string(char *format, char *value, t_args *args)
{
	char	*string;

	if (!value)
		string = ft_strdup("(null)");
	else
		string = ft_strdup(value);
	string = apply_precision(string, args);
	string = apply_width(string, args);
	format = ft_str_replace(format, args->argument, string);
	ft_free_ptr((void *)&string);
	return (format);
}

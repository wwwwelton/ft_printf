/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 01:43:23 by wleite            #+#    #+#             */
/*   Updated: 2021/10/12 10:55:15 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_width(char *pointer, t_args *args)
{
	char	*width;

	args->width -= ft_strlen(pointer);
	if (args->width > 0)
	{
		width = ft_char_to_str(' ', args->width);
		if (args->minus)
			pointer = ft_strmerge(pointer, width);
		else
			pointer = ft_strmerge(width, pointer);
	}
	return (pointer);
}

char	*replace_pointer(char *format, unsigned long int value, t_args *args)
{
	char	*pointer;

	if (!value && IS_MACOS)
		pointer = ft_strdup("0x0");
	else if (!value)
		pointer = ft_strdup("(nil)");
	else
	{
		pointer = ft_uitoa_base(value, "0123456789abcdef");
		pointer = ft_strmerge(ft_strdup("0x"), pointer);
	}
	pointer = apply_width(pointer, args);
	format = ft_str_replace(format, args->argument, pointer);
	ft_free_ptr((void *)&pointer);
	return (format);
}

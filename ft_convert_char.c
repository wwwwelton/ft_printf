/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/10/10 03:56:14 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_width(char *ch, t_args *args)
{
	char	*tmp;
	char	*width;

	args->width -= 1;
	if (args->width > 0)
	{
		width = ft_char_to_str(' ', args->width);
		if (args->minus)
			tmp = ft_strjoin(ch, width);
		else
			tmp = ft_strjoin(width, ch);
		ft_free_ptr((void *)&ch);
		ft_free_ptr((void *)&width);
		return (tmp);
	}
	return (ch);
}

char	*replace_char(char *format, int value, t_args *args)
{
	char	*ch;

	if (value == 0)
		ch = ft_strdup(NULL_PATTERN);
	else
		ch = ft_char_to_str(value, 1);
	ch = apply_width(ch, args);
	format = ft_str_replace(format, args->argument, ch);
	ft_free_ptr((void *)&ch);
	return (format);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/09/29 20:42:17 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_char(char type)
{
	return (type == 'c');
}

char	*replace_char(char *format, int value)
{
	char	*ch;

	if (value == 0)
		ch = ft_strdup(NULL_PATTERN);
	else
		ch = ft_char_tostr(value);
	format = ft_str_replace(format, "%c", ch);
	ft_free_ptr((void *)&ch);
	return (format);
}

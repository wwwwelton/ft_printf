/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/10/09 16:06:07 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

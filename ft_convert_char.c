/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 17:55:48 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_char(char type)
{
	return (type == 'c');
}

char	*replace_char(char *format, int value)
{
	char	*old_adress;
	char	*ch;

	if (value == 0)
		ch = ft_strdup(NULL_PATTERN);
	else
		ch = ft_char_tostr(value);
	old_adress = format;
	format = str_replace(old_adress, "%c", ch);
	free_ptr(&ch);
	free_ptr(&old_adress);
	return (format);
}

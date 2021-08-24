/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 16:36:01 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_char(const char *format)
{
	if (!format || !*format)
		return (0);
	if (ft_strnstr((char *)format, "%c", 2))
		return (1);
	return (0);
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

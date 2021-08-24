/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_un_int_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:58:20 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 18:50:01 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_un_int_hex(char type)
{
	return (is_uinteger(type) || is_u_hexadecimal(type));
}

char	*parse_un_int_hex(char *format, char type, unsigned int value)
{
	if (type == 'u')
		format = replace_uinteger(format, value);
	if (type == 'x')
		format = replace_u_hexadecimal(format, type, value);
	if (type == 'X')
		format = replace_u_hexadecimal(format, type, value);
	return (format);
}

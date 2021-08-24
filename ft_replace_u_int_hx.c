/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_u_int_hx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:58:20 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 18:17:03 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_u_int_hex(char type)
{
	return (is_uinteger(type) || is_u_hexadecimal(type));
}

char	*replace_u_int_hex(char *format, char type, unsigned int value)
{
	if (type == 'u')
		format = replace_uinteger(format, value);
	if (type == 'x')
		format = replace_u_hexadecimal(format, type, value);
	if (type == 'X')
		format = replace_u_hexadecimal(format, type, value);
	return (format);
}

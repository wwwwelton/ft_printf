/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_u_int_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:58:20 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 19:26:17 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_u_int_hex(char type)
{
	return (is_u_int(type) || is_u_hex(type));
}

char	*parse_u_int_hex(char *format, char type, unsigned int value)
{
	if (type == 'u')
		format = replace_u_int(format, value);
	if (type == 'x')
		format = replace_u_hex(format, type, value);
	if (type == 'X')
		format = replace_u_hex(format, type, value);
	return (format);
}

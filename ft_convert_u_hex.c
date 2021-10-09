/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/10/09 16:06:52 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*replace_u_hex(char *format, char type, unsigned int value)
{
	char	*hexadecimal;

	if (type == 'x')
	{
		hexadecimal = ft_uitoa_base(value, "0123456789abcdef");
		format = ft_str_replace(format, "%x", hexadecimal);
	}
	if (type == 'X')
	{
		hexadecimal = ft_uitoa_base(value, "0123456789ABCDEF");
		format = ft_str_replace(format, "%X", hexadecimal);
	}
	ft_free_ptr((void *)&hexadecimal);
	return (format);
}

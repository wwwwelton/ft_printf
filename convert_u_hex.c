/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/25 15:48:34 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_u_hex(char type)
{
	return (type == 'x' || type == 'X');
}

char	*replace_u_hex(char *format, char type, unsigned int value)
{
	char	*old_adress;
	char	*hexadecimal;

	old_adress = format;
	if (type == 'x')
	{
		hexadecimal = ft_uitoa_base(value, "0123456789abcdef");
		format = str_replace(old_adress, "%x", hexadecimal);
	}
	if (type == 'X')
	{
		hexadecimal = ft_uitoa_base(value, "0123456789ABCDEF");
		format = str_replace(old_adress, "%X", hexadecimal);
	}
	free_ptr(&hexadecimal);
	free_ptr(&old_adress);
	return (format);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_ch_dec_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:58:20 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 18:35:58 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_ch_dec_int(char type)
{
	return (is_char(type) || is_decimal(type) || is_integer(type));
}

char	*replace_ch_dec_int(char *format, char type, int value)
{
	if (type == 'c')
		format = replace_char(format, value);
	if (type == 'd')
		format = replace_decimal(format, value);
	if (type == 'i')
		format = replace_integer(format, value);
	return (format);
}

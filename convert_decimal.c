/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/09/29 20:42:48 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_decimal(char type)
{
	return (type == 'd');
}

char	*replace_decimal(char *format, int value)
{
	char	*decimal;

	decimal = ft_itoa(value);
	format = ft_str_replace(format, "%d", decimal);
	ft_free_ptr((void *)&decimal);
	return (format);
}

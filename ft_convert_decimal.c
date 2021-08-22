/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/21 21:46:41 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_decimal(const char *format)
{
	if (!format || !*format)
		return (0);
	if (ft_strnstr(format, "%d", 2))
		return (1);
	return (0);
}

char	*replace_decimal(char *format, int value)
{
	char	*old_address;
	char	*decimal;

	if (!format || !*format)
		return (NULL);
	old_address = format;
	decimal = ft_itoa(value);
	format = str_replace(old_address, "%d", decimal);
	free_ptr(&old_address);
	free_ptr(&decimal);
	return (format);
}

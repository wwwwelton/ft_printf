/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/22 10:32:07 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_decimal(const char *format)
{
	if (!format || !*format)
		return (0);
	if (ft_strnstr(format, "%d", 2) || ft_strnstr(format, "%i", 2))
		return (1);
	return (0);
}

char	*replace_decimal(char *format, int value)
{
	char	*decimal;
	int		replaced;
	int		i;

	decimal = ft_itoa(value);
	replaced = 0;
	i = 0;
	while (format[i] && !replaced)
	{
		if (format[i] == '%' && format[i + 1] == 'd')
			replaced = str_replace(&format, "%d", decimal);
		if (format[i] == '%' && format[i + 1] == 'i')
			replaced = str_replace(&format, "%i", decimal);
		i++;
	}
	free_ptr(&decimal);
	return (format);
}

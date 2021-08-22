/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/22 14:52:54 by wleite           ###   ########.fr       */
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
	char	*old_adress;
	char	*decimal;
	int		i;

	old_adress = format;
	decimal = ft_itoa(value);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			format = str_replace(old_adress, "%d", decimal);
			break ;
		}
		if (format[i] == '%' && format[i + 1] == 'i')
		{
			format = str_replace(old_adress, "%i", decimal);
			break ;
		}
		i++;
	}
	free_ptr(&decimal);
	free_ptr(&old_adress);
	return (format);
}

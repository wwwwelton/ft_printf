/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/25 18:32:32 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_decimal(char type)
{
	return (type == 'd');
}

char	*replace_decimal(char *format, int value)
{
	char	*old_adress;
	char	*decimal;

	old_adress = format;
	decimal = ft_itoa(value);
	format = ft_str_replace(old_adress, "%d", decimal);
	ft_free_ptr((void *)&decimal);
	ft_free_ptr((void *)&old_adress);
	return (format);
}

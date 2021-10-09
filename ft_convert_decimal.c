/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/10/09 16:06:14 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*replace_decimal(char *format, int value)
{
	char	*decimal;

	decimal = ft_itoa(value);
	format = ft_str_replace(format, "%d", decimal);
	ft_free_ptr((void *)&decimal);
	return (format);
}

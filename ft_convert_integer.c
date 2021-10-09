/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:31:28 by wleite            #+#    #+#             */
/*   Updated: 2021/10/09 16:06:19 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*replace_integer(char *format, int value)
{
	char	*decimal;

	decimal = ft_itoa(value);
	format = ft_str_replace(format, "%i", decimal);
	ft_free_ptr((void *)&decimal);
	return (format);
}

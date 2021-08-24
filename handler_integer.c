/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:31:28 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 19:44:54 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_integer(char type)
{
	return (type == 'i');
}

char	*replace_integer(char *format, int value)
{
	char	*old_adress;
	char	*decimal;

	old_adress = format;
	decimal = ft_itoa(value);
	format = str_replace(old_adress, "%i", decimal);
	free_ptr(&decimal);
	free_ptr(&old_adress);
	return (format);
}

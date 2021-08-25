/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 01:43:23 by wleite            #+#    #+#             */
/*   Updated: 2021/08/25 15:48:30 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_pointer(char type)
{
	return (type == 'p');
}

char	*replace_pointer(char *format, unsigned long int value)
{
	char	*old_adress;
	char	*pointer;
	char	*prefix;

	old_adress = format;
	pointer = ft_uitoa_base(value, "0123456789abcdef");
	if (value == 0)
		prefix = ft_strdup("0x0");
	else
		prefix = ft_strjoin("0x", pointer);
	format = str_replace(old_adress, "%p", prefix);
	free_ptr(&pointer);
	free_ptr(&prefix);
	free_ptr(&old_adress);
	return (format);
}

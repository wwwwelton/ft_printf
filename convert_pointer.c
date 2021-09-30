/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 01:43:23 by wleite            #+#    #+#             */
/*   Updated: 2021/09/29 20:44:26 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_pointer(char type)
{
	return (type == 'p');
}

char	*replace_pointer(char *format, unsigned long int value)
{
	char	*pointer;
	char	*prefix;

	pointer = ft_uitoa_base(value, "0123456789abcdef");
	if (value == 0)
		prefix = ft_strdup("0x0");
	else
		prefix = ft_strjoin("0x", pointer);
	format = ft_str_replace(format, "%p", prefix);
	ft_free_ptr((void *)&pointer);
	ft_free_ptr((void *)&prefix);
	return (format);
}

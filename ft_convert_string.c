/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/22 02:07:22 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_string(const char *format)
{
	if (!format || !*format)
		return (0);
	if (ft_strnstr(format, "%s", 2))
		return (1);
	return (0);
}

char	*replace_string(char *format, char *value)
{
	char	*old_address;
	char	*string;

	old_address = format;
	string = ft_strdup(value);
	format = str_replace(old_address, "%s", string);
	free_ptr(&old_address);
	free_ptr(&string);
	return (format);
}

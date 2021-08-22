/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/22 04:53:44 by wleite           ###   ########.fr       */
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
	char	*string;

	string = ft_strdup(value);
	str_replace(&format, "%s", string);
	free_ptr(&string);
	return (format);
}

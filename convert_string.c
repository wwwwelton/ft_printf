/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/09/29 20:44:39 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_string(char type)
{
	return (type == 's');
}

char	*replace_string(char *format, char *value)
{
	char	*string;

	if (!value)
		string = ft_strdup("(null)");
	else
		string = ft_strdup(value);
	format = ft_str_replace(format, "%s", string);
	ft_free_ptr((void *)&string);
	return (format);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/09/29 20:44:09 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_percent(char type)
{
	return (type == '%');
}

char	*replace_percent(char *format)
{
	char	*percent;

	percent = ft_strdup(PERCENT_PATTERN);
	format = ft_str_replace(format, "%%", percent);
	ft_free_ptr((void *)&percent);
	return (format);
}

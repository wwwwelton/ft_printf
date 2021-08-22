/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/22 04:53:16 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_percent(const char *format)
{
	if (!format || !*format)
		return (0);
	if (ft_strnstr(format, "%%", 2))
		return (1);
	return (0);
}

char	*replace_percent(char *format)
{
	char	*percent;

	percent = ft_strdup(PERCENT_PATTERN);
	str_replace(&format, "%%", percent);
	free_ptr(&percent);
	return (format);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/22 01:41:09 by wleite           ###   ########.fr       */
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
	char	*old_address;
	char	percent_parse[2];
	char	*percent;

	if (!format || !*format)
		return (NULL);
	old_address = format;
	percent_parse[0] = '%';
	percent_parse[1] = '\0';
	percent = ft_strdup("#");
	format = str_replace(old_address, "%%", percent);
	free_ptr(&old_address);
	free_ptr(&percent);
	return (format);
}

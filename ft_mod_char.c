/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/21 16:05:28 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_char(char *format)
{
	if (!format || !*format)
		return (0);
	if (ft_strnstr(format, "%c", 2))
		return (1);
	return (0);
}

char	*replace_char(char *format, int value)
{
	char	*old_address;
	char	ch_parse[2];
	char	*ch;

	if (!format || !*format)
		return (NULL);
	old_address = format;
	ch_parse[0] = value;
	ch_parse[1] = '\0';
	ch = ft_strdup(ch_parse);
	format = str_replace(old_address, "%c", ch);
	free_ptr(&old_address);
	free_ptr(&ch);
	return (format);
}

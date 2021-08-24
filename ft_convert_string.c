/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 17:56:24 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_string(char type)
{
	return (type == 's');
}

char	*replace_string(char *format, char *value)
{
	char	*old_adress;
	char	*string;

	if (!value)
		string = ft_strdup("(null)");
	else
		string = ft_strdup(value);
	old_adress = format;
	format = str_replace(old_adress, "%s", string);
	free_ptr(&string);
	free_ptr(&old_adress);
	return (format);
}

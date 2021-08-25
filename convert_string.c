/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/25 18:33:32 by wleite           ###   ########.fr       */
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
	format = ft_str_replace(old_adress, "%s", string);
	ft_free_ptr((void *)&string);
	ft_free_ptr((void *)&old_adress);
	return (format);
}

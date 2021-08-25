/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:24:16 by wleite            #+#    #+#             */
/*   Updated: 2021/08/25 18:33:49 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_u_int(char type)
{
	return (type == 'u');
}

char	*replace_u_int(char *format, unsigned int value)
{
	char	*old_adress;
	char	*uinteger;

	old_adress = format;
	uinteger = ft_uitoa_base(value, "0123456789");
	format = ft_str_replace(old_adress, "%u", uinteger);
	ft_free_ptr((void *)&uinteger);
	ft_free_ptr((void *)&old_adress);
	return (format);
}

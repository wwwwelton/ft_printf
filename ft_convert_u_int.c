/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:24:16 by wleite            #+#    #+#             */
/*   Updated: 2021/10/09 16:06:59 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*replace_u_int(char *format, unsigned int value)
{
	char	*uinteger;

	uinteger = ft_uitoa_base(value, "0123456789");
	format = ft_str_replace(format, "%u", uinteger);
	ft_free_ptr((void *)&uinteger);
	return (format);
}

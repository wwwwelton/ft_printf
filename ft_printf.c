/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:02:58 by wleite            #+#    #+#             */
/*   Updated: 2021/10/12 11:05:27 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	char	*fmt;
	va_list	ap;

	va_start(ap, format);
	fmt = parse_args(format, &ap);
	va_end(ap);
	len = print_to_fd(fmt, FD);
	ft_free_ptr((void *)&fmt);
	return (len);
}

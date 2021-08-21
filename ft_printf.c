/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:02:58 by wleite            #+#    #+#             */
/*   Updated: 2021/08/21 16:39:56 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*fmt;
	int		fmt_len;
	int		i;

	va_start(ap, format);
	fmt = ft_strdup(format);
	i = 0;
	while (fmt[i] != '\0')
	{
		if (is_decimal(&fmt[i]))
			fmt = replace_decimal(fmt, va_arg(ap, int));
		else if (is_string(&fmt[i]))
			fmt = replace_string(fmt, va_arg(ap, char *));
		else
			i++;
	}
	va_end(ap);
	fmt_len = ft_strlen(fmt);
	printf("%s", fmt);
	free_ptr(&fmt);
	return (fmt_len);
}

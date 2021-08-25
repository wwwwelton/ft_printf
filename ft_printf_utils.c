/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 01:53:59 by wleite            #+#    #+#             */
/*   Updated: 2021/08/25 18:26:45 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_to_fd(const char *format, int fd)
{
	int	bytes_write;

	bytes_write = 0;
	while (*format)
	{
		if (ft_strnstr(format, NULL_PATTERN, 9))
		{
			bytes_write += write(fd, "\0", 1);
			format += 9;
			continue ;
		}
		if (ft_strnstr(format, PERCENT_PATTERN, 10))
		{
			bytes_write += write(fd, "%", 1);
			format += 10;
			continue ;
		}
		bytes_write += write(fd, format, 1);
		format++;
	}
	return (bytes_write);
}

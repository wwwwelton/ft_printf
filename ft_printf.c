/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:02:58 by wleite            #+#    #+#             */
/*   Updated: 2021/08/21 02:49:42 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*p;
	char	*old_address;
	int		len;
	int		i;
	char	*str_s;
	char	*c_c;

	va_start(ap, format);
	p = ft_strdup(format);
	i = 0;
	while (p[i] != '\0')
	{
		if (is_decimal(&p[i]))
			p = replace_decimal(p, va_arg(ap, int));
		// if (ft_strnstr(&p[i], "%d", 2))
		// {
		// 	old_address = p;
		// 	int_d = ft_itoa(va_arg(ap, int));
		// 	p = str_replace(old_address, "%d", int_d);
		// 	free(old_address);
		// 	free(int_d);
		// }
		if (ft_strncmp(&p[i], "%s", 2) == 0)
		{
			old_address = p;
			str_s = ft_strdup((va_arg(ap, char *)));
			p = str_replace(old_address, "%s", str_s);
			free(old_address);
			free(str_s);
		}
		if (ft_strncmp(&p[i], "%c", 2) == 0)
		{
			old_address = p;
			c_c = (char *)ft_calloc(2, sizeof(char));
			c_c[0] = va_arg(ap, int);
			p = str_replace(old_address, "%c", c_c);
			free(old_address);
			free(c_c);
		}
		i++;
	}
	va_end(ap);
	len = ft_strlen(p);
	printf("%s", p);
	free(p);
	return (len);
}

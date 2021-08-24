/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u_hexadecimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 03:50:45 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*u_xtoa(unsigned int n);

size_t	is_u_hexadecimal(const char *format)
{
	if (!format || !*format)
		return (0);
	if (ft_strnstr(format, "%x", 2) || ft_strnstr(format, "%X", 2))
		return (1);
	return (0);
}

char	*replace_u_hexadecimal(char *format, unsigned int value)
{
	char	*old_adress;
	char	*hexadecimal;
	int		i;

	old_adress = format;
	hexadecimal = u_xtoa(value);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'x')
		{
			format = str_replace(old_adress, "%x", hexadecimal);
			break ;
		}
		if (format[i] == '%' && format[i + 1] == 'X')
		{
			ft_str_toupper(hexadecimal);
			format = str_replace(old_adress, "%X", hexadecimal);
			break ;
		}
		i++;
	}
	free_ptr(&hexadecimal);
	free_ptr(&old_adress);
	return (format);
}

static int	u_count_digits(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*u_xtoa(unsigned int n)
{
	char			*base;
	char			*res;
	unsigned int	i;

	if (n == 0)
		return (ft_strdup("0"));
	base = ft_strdup("0123456789abcdef");
	res = (char *)malloc(sizeof(char) * (u_count_digits(n) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (n)
	{
		res[i++] = base[(n % 16)];
		n = n / 16;
	}
	res[i] = '\0';
	ft_strrev(res);
	free_ptr(&base);
	return (res);
}

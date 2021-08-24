/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_u_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 19:21:54 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*u_xtoa(unsigned int n);

size_t	is_u_hex(char type)
{
	return (type == 'x' || type == 'X');
}

char	*replace_u_hex(char *format, char type, int value)
{
	char	*old_adress;
	char	*hexadecimal;

	old_adress = format;
	hexadecimal = u_xtoa(value);
	if (type == 'x')
		format = str_replace(old_adress, "%x", hexadecimal);
	if (type == 'X')
	{
		ft_str_toupper(hexadecimal);
		format = str_replace(old_adress, "%X", hexadecimal);
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

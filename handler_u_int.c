/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_u_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:24:16 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 19:25:02 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*u_itoa(unsigned int n);

size_t	is_u_int(char type)
{
	return (type == 'u');
}

char	*replace_u_int(char *format, unsigned int value)
{
	char	*old_adress;
	char	*uinteger;

	old_adress = format;
	uinteger = u_itoa(value);
	format = str_replace(old_adress, "%u", uinteger);
	free_ptr(&uinteger);
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

static char	*u_itoa(unsigned int n)
{
	char			*res;
	unsigned int	i;

	if (n == 0)
		return (ft_strdup("0"));
	res = (char *)malloc(sizeof(char) * (u_count_digits(n) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (n)
	{
		res[i++] = (n % 10) + '0';
		n = n / 10;
	}
	res[i] = '\0';
	ft_strrev(res);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 01:43:23 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 19:44:54 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ul_ptoa(unsigned long int n);

size_t	is_pointer(char type)
{
	return (type == 'p');
}

char	*replace_pointer(char *format, unsigned long int value)
{
	char	*old_adress;
	char	*pointer;
	char	*prefix;

	old_adress = format;
	pointer = ul_ptoa(value);
	if (value == 0)
		prefix = ft_strdup("0x0");
	else
		prefix = ft_strjoin("0x", pointer);
	format = str_replace(old_adress, "%p", prefix);
	free_ptr(&pointer);
	free_ptr(&prefix);
	free_ptr(&old_adress);
	return (format);
}

static int	u_count_digits(unsigned long int n)
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

static char	*ul_ptoa(unsigned long int n)
{
	char	*base;
	char	*res;
	int		i;

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

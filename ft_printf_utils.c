/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 01:53:59 by wleite            #+#    #+#             */
/*   Updated: 2021/10/12 11:03:21 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_args(t_args *args)
{
	args->negative = 0;
	args->hash = 0;
	args->minus = 0;
	args->plus = 0;
	args->space = 0;
	args->zero = 0;
	args->width = 0;
	args->dot = 0;
	args->precision = -1;
	args->type = 0;
	args->argument = NULL;
}

void	deinit_args(t_args *args)
{
	ft_free_ptr((void *)&args->argument);
}

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

char	*ft_char_to_str(char c, size_t len)
{
	char	*str;

	if (len < 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_memset(str, c, len);
	str[len] = '\0';
	return (str);
}

char	*ft_strmerge(char *s1, char *s2)
{
	char	*str;
	size_t	size;

	if (!s1 || !s2)
	{
		ft_free_ptr((void *)&s1);
		ft_free_ptr((void *)&s2);
		return (NULL);
	}
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, size);
	ft_free_ptr((void *)&s1);
	ft_free_ptr((void *)&s2);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 01:53:59 by wleite            #+#    #+#             */
/*   Updated: 2021/08/22 08:41:04 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

int	str_replace(char **str, char *old_word, char *new_word)
{
	char	*buffer;
	char	*p;
	int		len;
	int		i;

	len = ft_strlen(*str) - ft_strlen(old_word) + ft_strlen(new_word) + 1;
	buffer = (char *)ft_calloc(len, sizeof(char *));
	if (!buffer)
		return (0);
	i = 0;
	p = ft_strnstr(*str + i, old_word, ft_strlen(*str));
	if (p)
	{
		ft_strlcpy(buffer + ft_strlen(buffer), *str + i, (p - *str) - i + 1);
		ft_strlcat(buffer, new_word, len);
		i = (p - *str) + ft_strlen(old_word);
	}
	ft_strlcat(buffer, *str + i, len);
	free_ptr(str);
	*str = buffer;
	return (len);
}

int	print_pattern_fd(const char **format, char *pattern, int *bytes_write)
{
	if (ft_strnstr(*format, pattern, ft_strlen(pattern)))
	{
		*bytes_write += write(FD, "\0", 1);
		*format += ft_strlen(pattern);
		return (1);
	}
	return (0);
}

int	ft_print_parser_fd(const char *format)
{
	int	bytes_write;

	bytes_write = 0;
	while (*format)
	{
		if (print_pattern_fd(&format, NULL_PATTERN, &bytes_write))
			continue ;
		if (ft_strnstr(format, PERCENT_PATTERN, 10))
		{
			bytes_write += write(FD, "%", 1);
			format += 10;
			continue ;
		}
		bytes_write += write(FD, format, 1);
		format++;
	}
	return (bytes_write);
}

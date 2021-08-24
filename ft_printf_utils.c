/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 01:53:59 by wleite            #+#    #+#             */
/*   Updated: 2021/08/24 18:26:44 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*str_replace(const char *str, char *old_word, char *new_word)
{
	char	*new_str;
	char	*ptr;
	int		total_size;
	int		i;

	total_size = ft_strlen(str) - ft_strlen(old_word) + ft_strlen(new_word) + 1;
	new_str = (char *)ft_calloc(total_size, sizeof(char *));
	if (!new_str)
		return (NULL);
	i = 0;
	ptr = ft_strnstr(str + i, old_word, ft_strlen(str));
	if (ptr)
	{
		ft_strlcpy(new_str + ft_strlen(new_str), str + i, (ptr - str) - i + 1);
		ft_strlcat(new_str, new_word, total_size);
		i = (ptr - str) + ft_strlen(old_word);
	}
	ft_strlcat(new_str, str + i, total_size);
	return (new_str);
}

int	ft_print_parser_fd(const char *format)
{
	int	bytes_write;

	bytes_write = 0;
	while (*format)
	{
		if (ft_strnstr(format, NULL_PATTERN, 9))
		{
			bytes_write += write(FD, "\0", 1);
			format += 9;
			continue ;
		}
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

void	ft_strrev(char *str)
{
	char	temp;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(str) - 1;
	if (str[start] == '-')
		start++;
	while (str[start] && start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

int		ft_str_toupper(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (i);
}

char	*ft_char_tostr(char c)
{
	char	str[2];

	if (c == '\0')
		return (ft_strdup(""));
	str[0] = c;
	str[1] = '\0';
	return (ft_strdup(str));
}

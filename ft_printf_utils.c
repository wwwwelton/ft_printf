/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 01:53:59 by wleite            #+#    #+#             */
/*   Updated: 2021/08/25 01:00:24 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_ptr(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

char	*str_replace(const char *str, char *old_word, char *new_word)
{
	char	*new_str;
	char	*ptr;
	int		total_size;
	int		i;

	if (!str || !old_word || !new_word)
		return (NULL);
	total_size = ft_strlen(str) - ft_strlen(old_word) + ft_strlen(new_word) + 1;
	new_str = (char *)ft_calloc(total_size, sizeof(char *));
	if (!new_str)
		return (NULL);
	i = 0;
	ptr = ft_strnstr(str, old_word, ft_strlen(str));
	if (ptr)
	{
		ft_strlcpy(new_str, str, (ptr - str) + 1);
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
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= 32;
			i++;
		}
		str++;
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

static int	ft_count_digits(unsigned long long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_lluitoa_base(unsigned long long int n, char *base)
{
	char	*str;
	size_t	base_len;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (ft_count_digits(n) + 1));
	if (!str)
		return (NULL);
	base_len = ft_strlen(base);
	i = 0;
	if (n < 0)
	{
		n = -n;
		str[i++] = '-';
	}
	while (n)
	{
		str[i++] = base[n % base_len];
		n = n / base_len;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:02:58 by wleite            #+#    #+#             */
/*   Updated: 2021/08/20 19:35:54 by wleite           ###   ########.fr       */
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
	char	*int_d;
	char	*str_s;
	char	*c_c;

	va_start(ap, format);
	p = ft_strdup(format);
	i = 0;
	while (p[i] != '\0')
	{
		if (ft_strncmp(&p[i], "%d", 2) == 0)
		{
			old_address = p;
			int_d = ft_itoa(va_arg(ap, int));
			p = str_replace(old_address, "%d", int_d);
			free(old_address);
			free(int_d);
		}
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

char	*str_replace(char *str, char *old_word, char *new_word)
{
	char	*result;
	char	*result_ptr;
	size_t	old_word_len;
	size_t	new_word_len;
	size_t	str_len;
	size_t	replaced;

	old_word_len = ft_strlen(old_word);
	new_word_len = ft_strlen(new_word);
	str_len = ft_strlen(str);
	result_ptr = (char *)malloc((str_len - old_word_len + new_word_len) + 1);
	if (!result_ptr)
		return (NULL);
	*result_ptr = '\0';
	result = result_ptr;
	replaced = 0;
	while (*str)
	{
		if (!ft_strncmp (str, old_word, old_word_len) && !replaced)
		{
			ft_strlcat (result, new_word, new_word_len + 1);
			str += old_word_len;
			result += new_word_len;
			replaced = 1;
		}
		else
		{
			*result = *str;
			result++;
			str++;
		}
		*result = '\0';
	}
	return (result_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 01:53:59 by wleite            #+#    #+#             */
/*   Updated: 2021/08/22 04:46:52 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*str_replace(char *str, char *old_word, char *new_word)
{
	char	*buffer;
	char	*p;
	int		len;
	int		i;

	len = ft_strlen(str) - ft_strlen(old_word) + ft_strlen(new_word) + 1;
	buffer = (char *)ft_calloc(len, sizeof(char *));
	i = 0;
	p = ft_strnstr(str + i, old_word, ft_strlen(str));
	if (p)
	{
		ft_strlcpy(buffer + ft_strlen(buffer), str + i, (p - str) - i + 1);
		ft_strlcat(buffer, new_word, len);
		i = (p - str) + ft_strlen(old_word);
	}
	ft_strlcat(buffer, str + i, len);
	return (buffer);
}

// char	*str_replace(char *str, char *old_word, char *new_word)
// {
// 	char	*result;
// 	char	*result_start;
// 	size_t	replaced;

// 	result = (char *)ft_calloc((ft_strlen(str) - ft_strlen(old_word)
// 				+ ft_strlen(new_word) + 1), sizeof(char *));
// 	result_start = result;
// 	replaced = 0;
// 	while (*str)
// 	{
// 		if (!ft_strncmp (str, old_word, ft_strlen(old_word)) && !replaced)
// 		{
// 			ft_strlcat (result, new_word, ft_strlen(new_word) + 1);
// 			str += ft_strlen(old_word);
// 			result += ft_strlen(new_word);
// 			replaced = 1;
// 		}
// 		else
// 		{
// 			*result = *str;
// 			result++;
// 			str++;
// 		}
// 	}
// 	return (result_start);
// }

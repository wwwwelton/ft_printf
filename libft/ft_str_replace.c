/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:03:55 by wleite            #+#    #+#             */
/*   Updated: 2021/09/29 22:01:27 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_replace(char *str,	const char *old_word, const char *new_word)
{
	int		i;
	int		total_size;
	char	*ptr;
	char	*new_str;

	if (!str || !old_word || !new_word)
		return (NULL);
	ptr = ft_strnstr(str, old_word, ft_strlen(str));
	if (!ptr)
	{
		new_str = ft_strdup(str);
		ft_free_ptr((void *)&str);
		return (new_str);
	}
	total_size = ft_strlen(str) - ft_strlen(old_word) + ft_strlen(new_word) + 1;
	new_str = (char *)malloc(sizeof(char) * total_size);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str, (ptr - str) + 1);
	ft_strlcat(new_str, new_word, total_size);
	i = (ptr - str) + ft_strlen(old_word);
	ft_strlcat(new_str, &str[i], total_size);
	ft_free_ptr((void *)&str);
	return (new_str);
}

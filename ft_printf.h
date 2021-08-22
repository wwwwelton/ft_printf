/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 06:03:07 by wleite            #+#    #+#             */
/*   Updated: 2021/08/22 01:36:06 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

int		ft_printf(const char *format, ...);
void	free_ptr(char **ptr);
char	*str_replace(char *str, char *old_word, char *new_word);

size_t	is_decimal(const char *format);
char	*replace_decimal(char *format, int value);

size_t	is_string(const char *format);
char	*replace_string(char *format, char *value);

size_t	is_char(const char *format);
char	*replace_char(char *format, int value);

size_t	is_percent(const char *format);
char	*replace_percent(char *format);

#endif

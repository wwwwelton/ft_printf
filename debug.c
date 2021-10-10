/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:11:13 by wleite            #+#    #+#             */
/*   Updated: 2021/10/10 00:54:31 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	debug(t_args *args)
{
	printf("\n\n--------------");
	printf("hash: %d\n", args->hash);
	printf("minus: %d\n", args->minus);
	printf("plus: %d\n", args->plus);
	printf("space: %d\n", args->space);
	printf("zero: %d\n", args->zero);
	printf("width: %d\n", args->width);
	printf("precision: %d\n", args->precision);
	printf("type: %c\n", args->type);
	printf("argument: $%s$\n", args->argument);
	printf("len: %d\n", args->len);
	printf("--------------\n\n");
}

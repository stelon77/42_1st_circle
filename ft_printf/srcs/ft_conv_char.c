/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:21:18 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/01/31 11:51:03 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	error(t_convers *conv, int n)
{
	conv->error = n;
	return (0);
}

int			conv_char(t_convers *conv, va_list ap)
{
	unsigned char	c;
	int				n;
	int				i;

	c = va_arg(ap, int);
	if (c == 0)
		conv->ret_count = 1;
	n = 1;
	if (conv->min_width > 1)
		n = conv->min_width;
	if (!(conv->str_to_add = ft_calloc((n + 1), sizeof(char))))
		return (error(conv, -1));
	i = n;
	while (--i >= 0)
		(conv->str_to_add)[i] = ' ';
	if ((conv->flag & MINUS) && (!conv->ret_count))
		conv->str_to_add[0] = c;
	else
		conv->str_to_add[n - 1] = c;
	return (1);
}

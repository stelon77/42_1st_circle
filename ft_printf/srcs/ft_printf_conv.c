/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:43:37 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/01/31 11:50:09 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_conv(t_convers *conv, va_list ap, char c)
{
	if (c == 'c')
		conv_char(conv, ap);
	else if (c == 's')
		conv_str(conv, ap);
	else if (c == 'p')
		conv_ptr(conv, ap);
	else if (c == 'd' || c == 'i')
		conv_int(conv, ap);
	else if (c == 'u' || c == 'x' || c == 'X')
		conv_unsigned_int(conv, ap, c);
	else if (c == '%')
		conv_percent(conv);
	return ;
}

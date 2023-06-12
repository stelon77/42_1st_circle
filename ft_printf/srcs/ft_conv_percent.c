/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:08:00 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/01/31 11:50:49 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	error(t_convers *conv, int n)
{
	conv->error = n;
	return (0);
}

static void	flag_gestion(t_convers *conv, int i, int n)
{
	if (conv->flag & ZERO)
		while (--i >= 0)
			conv->str_to_add[i] = '0';
	else
		while (--i >= 0)
			conv->str_to_add[i] = ' ';
	if (conv->flag & MINUS)
		conv->str_to_add[0] = '%';
	else
		conv->str_to_add[n - 1] = '%';
}

int			conv_percent(t_convers *conv)
{
	int				n;
	int				i;

	n = 1;
	if ((conv->flag & ZERO) && (conv->flag & MINUS))
		conv->flag = conv->flag ^ ZERO;
	if (conv->min_width > 1)
		n = conv->min_width;
	if (!(conv->str_to_add = ft_calloc((n + 1), sizeof(char))))
		return (error(conv, -1));
	if (n == 1)
	{
		conv->str_to_add[0] = '%';
		return (1);
	}
	i = n;
	flag_gestion(conv, i, n);
	return (1);
}

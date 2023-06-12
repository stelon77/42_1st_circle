/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:36:55 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/01/31 11:50:21 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		error(t_convers *conv, char *str, int n)
{
	if (str)
		free(str);
	conv->error = n;
	return (0);
}

static char		*init_arg(va_list ap)
{
	char	*arg1;
	char	*arg2;

	arg1 = va_arg(ap, char*);
	if (arg1 == NULL)
	{
		if (!(arg2 = ft_strdup("(null)")))
			return (NULL);
		return (arg2);
	}
	if (!(arg2 = ft_strdup(arg1)))
		return (NULL);
	return (arg2);
}

int				conv_str(t_convers *conv, va_list ap)
{
	char			*arg;
	int				n;
	int				i;

	if (!(arg = init_arg(ap)))
		return (error(conv, NULL, -1));
	n = ft_strlen(arg);
	if ((conv->flag & DOT) && conv->precision < n)
		n = conv->precision;
	arg[n] = '\0';
	if (conv->min_width > n)
		n = conv->min_width;
	if (!(conv->str_to_add = ft_calloc((n + 1), sizeof(char))))
		return (error(conv, arg, -1));
	i = n;
	while (--i >= 0)
		(conv->str_to_add)[i] = ' ';
	if (conv->flag & MINUS)
		ft_memcpy(conv->str_to_add, arg, ft_strlen(arg));
	else
		ft_memcpy(&conv->str_to_add[n - ft_strlen(arg)], arg, ft_strlen(arg));
	free(arg);
	return (1);
}

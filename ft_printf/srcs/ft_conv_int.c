/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:09:27 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/01/31 11:50:57 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*errorandfree(t_convers *conv, int n, char *str, char *ret)
{
	conv->error = n;
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (ret);
}

static unsigned int	initialize(int arg, t_convers *conv)
{
	if ((conv->flag & ZERO) && (conv->flag & MINUS))
		conv->flag ^= ZERO;
	if ((conv->flag & ZERO) && (!(conv->flag & DOT)))
		conv->precision = conv->min_width;
	if (arg < 0)
		return (-arg);
	else
		return (arg);
}

int					change_length(t_convers *conv, int arg, int i)
{
	if (arg < 0)
		i++;
	if (conv->precision > i)
		i = conv->precision;
	if ((arg < 0) && (conv->flag & DOT) && (conv->precision == i))
		i++;
	return (i);
}

static char			*create_str(t_convers *conv, unsigned int uarg, int arg)
{
	char	*str;
	int		i;
	char	*str2;

	if (!(str = ft_itoa_base_long((long)uarg, "0123456789")))
		return (NULL);
	if ((arg == 0) && ((conv->flag & DOT) && conv->precision == 0))
	{
		free(str);
		if (!(str = ft_strdup("")))
			return (NULL);
	}
	i = ft_strlen(str);
	i = change_length(conv, arg, i);
	if (!(str2 = ft_calloc((i + 1), sizeof(char))))
		return (errorandfree(conv, -1, str, NULL));
	while (--i >= 0)
		str2[i] = '0';
	if (arg < 0)
		str2[0] = '-';
	ft_memcpy(&str2[ft_strlen(str2) - ft_strlen(str)], str, ft_strlen(str));
	return (errorandfree(conv, 0, str, str2));
}

char				*conv_int(t_convers *conv, va_list ap)
{
	int				arg;
	unsigned int	uarg;
	int				n;
	int				i;
	char			*str;

	arg = va_arg(ap, int);
	uarg = initialize(arg, conv);
	if (!(str = create_str(conv, uarg, arg)))
		return (errorandfree(conv, -1, NULL, NULL));
	n = ft_strlen(str);
	if (conv->min_width > n)
		n = conv->min_width;
	if (!(conv->str_to_add = ft_calloc((n + 1), sizeof(char))))
		return (errorandfree(conv, -1, str, NULL));
	i = n;
	while (--i >= 0)
		(conv->str_to_add)[i] = ' ';
	if (conv->flag & MINUS)
		ft_memcpy(conv->str_to_add, str, ft_strlen(str));
	else
		ft_memcpy(&conv->str_to_add[n - ft_strlen(str)], str, ft_strlen(str));
	return (errorandfree(conv, 0, str, NULL));
}

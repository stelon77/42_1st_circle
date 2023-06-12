/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:05:57 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/01/31 11:50:15 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	str_free(char *str, t_convers *conv, int ret)
{
	if (conv->error != -1)
		if (str)
		{
			free(str);
			str = NULL;
		}
	return (ret);
}

static int	error(t_convers *conv, int n)
{
	conv->error = n;
	return (0);
}

static char	*choice(t_convers *conv, unsigned int arg, char c)
{
	char	*str;

	if ((arg == 0) && ((conv->flag & DOT_ALONE) ||
			((conv->flag & DOT) && conv->precision == 0)))
		str = ft_strdup("");
	else if (c == 'u')
		str = ft_itoa_base_long((long)arg, "0123456789");
	else if (c == 'x')
		str = ft_itoa_base_long((long)arg, "0123456789abcdef");
	else
	{
		str = ft_itoa_base_long((long)arg, "0123456789ABCDEF");
	}
	if (str == NULL)
	{
		conv->error = -1;
		return ("");
	}
	return (str);
}

static char	*create_str_unsigned(t_convers *conv, unsigned int arg, char c)
{
	char	*str;
	int		i;
	char	*str2;

	str = choice(conv, arg, c);
	i = ft_strlen(str);
	if (conv->precision > i)
		i = conv->precision;
	if (!(str2 = ft_calloc((i + 1), sizeof(char))))
	{
		error(conv, -1);
		return ("");
	}
	while (--i >= 0)
		str2[i] = '0';
	ft_memcpy(&str2[ft_strlen(str2) - ft_strlen(str)], str, ft_strlen(str));
	str_free(str, conv, 0);
	return (str2);
}

int			conv_unsigned_int(t_convers *conv, va_list ap, char c)
{
	unsigned int	arg;
	int				n;
	int				i;
	char			*str;

	arg = va_arg(ap, unsigned int);
	if ((conv->flag & ZERO) && (conv->flag & MINUS))
		conv->flag ^= ZERO;
	if ((conv->flag & ZERO) && (!(conv->flag & DOT)))
		conv->precision = conv->min_width;
	str = create_str_unsigned(conv, arg, c);
	n = ft_strlen(str);
	if (conv->min_width > n)
		n = conv->min_width;
	if (!(conv->str_to_add = ft_calloc((n + 1), sizeof(char))))
		return (error(conv, -1));
	i = n;
	while (--i >= 0)
		(conv->str_to_add)[i] = ' ';
	if (conv->flag & MINUS)
		ft_memcpy(conv->str_to_add, str, ft_strlen(str));
	else
		ft_memcpy(&conv->str_to_add[n - ft_strlen(str)], str, ft_strlen(str));
	return (str_free(str, conv, 1));
}

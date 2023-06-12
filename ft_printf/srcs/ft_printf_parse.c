/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 23:08:40 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/01/31 11:49:51 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		put_flag(t_convers *conv, const char *text, int index)
{
	conv->flag = conv->flag | FLAGOK;
	if (text[index] == '-')
		conv->flag = conv->flag | MINUS;
	if (text[index] == '0')
		conv->flag = conv->flag | ZERO;
	return (1);
}

static int		is_in_string(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static int		width(t_convers *conv, va_list ap, const char *text, int index)
{
	if (text[index] == '*')
	{
		conv->min_width = va_arg(ap, int);
		if (conv->min_width < 0)
		{
			conv->flag = conv->flag | MINUS;
			conv->min_width = -(conv->min_width);
		}
		return (index + 1);
	}
	conv->min_width = ft_atoi_parse(&text[index], &index, conv);
	return (index);
}

static int		precision(t_convers *conv, va_list ap,
					const char *text, int index)
{
	conv->flag |= DOT;
	index++;
	if ((!(ft_isdigit(text[index]))) && text[index] != '*')
		conv->flag = conv->flag | DOT_ALONE;
	if (text[index] == '*')
	{
		conv->precision = va_arg(ap, int);
		if (conv->precision < 0)
		{
			conv->precision = 0;
			conv->flag ^= DOT;
		}
		return (index + 1);
	}
	conv->precision = ft_atoi_parse(&text[index], &index, conv);
	return (index);
}

int				ft_printf_parse(t_convers *conv, va_list ap,
					int index, const char *text)
{
	int j;

	j = index;
	init_t_convers(conv);
	while (is_in_string(text[j], FLAG))
	{
		put_flag(conv, text, j);
		j++;
	}
	if (ft_isdigit(text[j]) || text[j] == '*')
		j = width(conv, ap, text, j);
	if (text[j] == '.')
		j = precision(conv, ap, text, j);
	if (is_in_string(text[j], CONV))
		ft_printf_conv(conv, ap, text[j]);
	return (j - index + 1);
}

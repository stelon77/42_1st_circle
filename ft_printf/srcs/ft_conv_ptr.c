/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:42:23 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/01/31 11:50:29 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	error(t_convers *conv, int n)
{
	conv->error = n;
	return (0);
}

static int	error2(t_convers *conv, int n, char *str1)
{
	if (str1)
	{
		free(str1);
		str1 = NULL;
	}
	conv->error = n;
	return (0);
}

static int	str_free(char *str1, char *str2, int ret)
{
	if (str1)
	{
		free(str1);
		str1 = NULL;
	}
	if (str2)
	{
		free(str2);
		str2 = NULL;
	}
	return (ret);
}

static char	*special_case(char *str, t_convers *conv, void *arg)
{
	if ((conv->flag & DOT_ALONE) && arg == NULL)
		return (ft_strdup("0x"));
	else
		return (ft_strjoin("0x", str));
}

int			conv_ptr(t_convers *conv, va_list ap)
{
	void			*arg;
	int				n;
	int				i;
	char			*str;
	char			*str2;

	arg = va_arg(ap, void*);
	if (!(str = ft_itoa_base_long((long)arg, "0123456789abcdef")))
		return (error(conv, -1));
	if (!(str2 = special_case(str, conv, arg)))
		return (error2(conv, -1, str));
	n = ft_strlen(str2);
	if (conv->min_width > n)
		n = conv->min_width;
	if (!(conv->str_to_add = ft_calloc((n + 1), sizeof(char))))
		return (error(conv, -1));
	i = n;
	while (--i >= 0)
		(conv->str_to_add)[i] = ' ';
	i = ft_strlen(str2);
	if (conv->flag & MINUS)
		ft_memcpy(conv->str_to_add, str2, i);
	else
		ft_memcpy(&conv->str_to_add[n - i], str2, i);
	return (str_free(str, str2, 1));
}

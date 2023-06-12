/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:20:36 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/01/31 11:49:40 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	free_mem(t_convers *conv, int ret)
{
	if (conv->str_to_add)
		free(conv->str_to_add);
	conv->str_to_add = NULL;
	return (ret);
}

static int	preparse(t_convers *conv, va_list ap, int *index, const char *text)
{
	int	i;

	i = 0;
	*index += 1;
	*index += ft_printf_parse(conv, ap, *index, text);
	if (conv->ret_count && (conv->flag & MINUS))
		ft_putchar_fd(0, 1);
	ft_putstr_fd(conv->str_to_add, 1);
	if (conv->ret_count && (!(conv->flag & MINUS)))
		ft_putchar_fd(0, 1);
	if (!conv->str_to_add)
		if (!(conv->str_to_add = ft_strdup("")))
			conv->error = -1;
	if (conv->error != 0)
		conv->error = -2147483648;
	i = ft_strlen(conv->str_to_add) + conv->ret_count + conv->error;
	free_mem(conv, 1);
	return (i);
}

void		writing(char c, int *index, int *count)
{
	ft_putchar_fd(c, 1);
	*index = *index + 1;
	*count = *count + 1;
}

int			ft_printf(const char *text, ...)
{
	int			count;
	va_list		ap;
	t_convers	conv;
	int			index;

	va_start(ap, text);
	count = 0;
	index = 0;
	while (text[index] != '\0' && count >= 0)
	{
		if (text[index] == '%')
			count += preparse(&conv, ap, &index, text);
		else
			writing(text[index], &index, &count);
	}
	va_end(ap);
	return (count);
}

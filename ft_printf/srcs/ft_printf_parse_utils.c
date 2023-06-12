/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:08:17 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/01/31 11:50:02 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_t_convers(t_convers *conv)
{
	conv->flag = 0;
	conv->min_width = 0;
	conv->precision = 0;
	conv->length_modif = 0;
	conv->str_to_add = NULL;
	conv->ret_count = 0;
	conv->error = 0;
}

int		ft_atoi_parse(const char *str, int *index, t_convers *conv)
{
	int i;
	int nbr;
	int	zero;

	i = 0;
	nbr = 0;
	zero = 0;
	if (str[i] == '-')
	{
		i++;
		zero = 1;
		conv->flag = conv->flag | MINUS;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	*index += i;
	if (zero)
		nbr = 0;
	return (nbr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 13:43:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/01/26 00:18:53 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_convers
{
	short int		flag;
	int				min_width;
	int				precision;
	int				length_modif;
	char			*str_to_add;
	int				ret_count;
	int				error;
}				t_convers;

# define FLAG "0-"
# define CONV "cspdiuxX%"
# define FLAGOK 1
# define MINUS 2
# define ZERO 4
# define DOT 8
# define DOT_ALONE 16

int				ft_printf(const char *text, ...);
void			init_t_convers(t_convers *conv);
int				ft_atoi_parse(const char *str, int *index, t_convers *conv);
int				conv_char(t_convers *conv, va_list ap);
char			*conv_int(t_convers *conv, va_list ap);
int				conv_percent(t_convers *conv);
int				conv_ptr(t_convers *conv, va_list ap);
int				conv_str(t_convers *conv, va_list ap);
int				conv_unsigned_int(t_convers *conv, va_list ap, char c);
void			ft_printf_conv(t_convers *conv, va_list ap, char c);
int				ft_printf_parse(t_convers *conv, va_list ap, int index,
					const char *text);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
int				ft_isdigit(int c);
char			*ft_itoa_base_long(long int n, char *base);
char			*ft_itoa_base(int n, char *base);
char			*ft_itoa(int n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_base(int nbr, char *base);
void			t_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);

#endif

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 10:44:40 by lcoiffie          #+#    #+#              #
#    Updated: 2020/01/31 11:57:51 by lcoiffie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

LIBFT_A =	libft.a

COMP =		gcc -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H =	-I includes/

LIBFT_H = 	-I srcs/libft/includes

OBJ_DIR =	obj/

SRC_DIR =	srcs/

LIB_DIR =	srcs/libft/

CFILE =		ft_printf.c \
			ft_conv_char.c \
			ft_conv_int.c \
			ft_conv_percent.c \
			ft_conv_ptr.c \
			ft_conv_str.c \
			ft_conv_unsigned.c \
			ft_printf_conv.c \
			ft_printf_parse_utils.c \
			ft_printf_parse.c \

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.c=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory
		
$(NAME): $(OBJ)
		@echo LIBFT START
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo FT_PRINTF COMPLETE
		
$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)
		
$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)
		
clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo Cleaned ft_printf object files
		
fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo Cleaned $(NAME)
		
re: fclean all

.PHONY: all clean flcean re

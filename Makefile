# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 23:55:35 by rtracee           #+#    #+#              #
#    Updated: 2021/05/28 21:33:09 by rtracee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_flagi.c ft_itoa.c ft_liba.c ft_printf3_adres.c ft_printf3_char.c ft_printf3_int.c ft_printf3_shest.c ft_printf3_stroka.c ft_unsigint.c ft_poisk.c

OBJ = $(patsubst %.c,%.o,$(SRCS))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 18:00:02 by ytouisse          #+#    #+#              #
#    Updated: 2022/11/08 21:29:05 by ytouisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRCS := ft_printf.c ft_printf_utils.c
OBJS := $(SRCS:.c=.o)

CFLAGS := -Wall -Wextra -Werror

.PHONY: all clean fclean re


all: $(NAME)


$(NAME): $(OBJS)
	ar -crs $@ $^

%.o: %.c ft_printf.h
	gcc $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 21:11:59 by ytouisse          #+#    #+#              #
#    Updated: 2022/12/08 15:23:56 by ytouisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minitalk.a

SRCS := client.c server.c utils.c
OBJS := $(SRCS:.c=.o)

CFLAGS := -Wall -Wextra -Werror

.PHONY: all clean fclean re


all: $(NAME)


$(NAME): $(OBJS)
	ar -crs $@ $^

%.o: %.c minitalk.h
	gcc $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
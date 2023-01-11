# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 23:02:33 by ytouisse          #+#    #+#              #
#    Updated: 2023/01/10 16:25:09 by ytouisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INC = fractol.h

SRCS = fractals.c fractol.c main.c utils.c complex.c colors.c events.c
OBJS := $(SRCS:.c=.o)
CC = cc

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all
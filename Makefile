# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalissa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 12:17:17 by aalissa           #+#    #+#              #
#    Updated: 2024/03/30 18:10:50 by aalissa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
SRC :=  main.c	events.c	fractol_init.c	input_handel.c	math_utils.c	render.c
OBJ := $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx-linux -l:libmlx.a -lXext -lX11
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

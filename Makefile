# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 13:55:13 by rle-mino          #+#    #+#              #
#    Updated: 2016/04/18 14:06:17 by rle-mino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=				ft_select

SRC		=				main.c

OBJ		=				$(SRC:.c=.o)

FLAGS	=				-Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	make -C libft
	gcc -c $(NAME) $(FLAGS) -lcurses $(OBJ) -lft -L ./libft

all: $(NAME)

%.o: %.c
	gcc -c $< -o $@ -I includes $(FLAGS)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all

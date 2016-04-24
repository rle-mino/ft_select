# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 13:55:13 by rle-mino          #+#    #+#              #
#    Updated: 2016/04/24 15:16:43 by rle-mino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=				ft_select

SRC		=				main.c			\
						sel_env.c		\
						sel_error.c		\
						argv_to_list.c	\
						sel_display.c	\
						putint.c		\
						move.c			\
						select.c		\
						sel_signal.c	\
						get_var.c		\
						sel_buf.c		\
						end_prog.c		\

OBJ		=				$(SRC:.c=.o)

FLAGS	=				-Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(FLAGS) -lcurses $(OBJ) -lft -L ./libft -I includes

all: $(NAME)

%.o: %.c
	gcc -c $< -o $@ -I includes $(FLAGS)

clean:
	make -C libft fclean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

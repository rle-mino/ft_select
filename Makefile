# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 13:55:13 by rle-mino          #+#    #+#              #
#    Updated: 2016/06/22 19:26:53 by rle-mino         ###   ########.fr        #
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
						status_bar.c	\
						next_occur.c	\
						time.c			\

OBJ_PATH	=			obj/

OBJ_NAME	=			$(SRC:.c=.o)
OBJ			=			$(addprefix $(OBJ_PATH),$(OBJ_NAME))
FLAGS		=			-Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
		make -C libft
		gcc -o $(NAME) $(FLAGS) -lmlx $^ -lft -L ./libft -I includes -lcurses

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir -p obj
	gcc $(FLAGS) -c $< -o $@ -I includes

clean:
	make -C libft fclean
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

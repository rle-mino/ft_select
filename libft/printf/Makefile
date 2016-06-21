# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/25 22:43:08 by rle-mino          #+#    #+#              #
#    Updated: 2016/05/25 22:50:19 by rle-mino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=		binary.c					\
				char_conv_l.c				\
				char_conv_noclong.c			\
				deci_conv_h.c				\
				deci_conv_hh.c				\
				deci_conv_j.c				\
				deci_conv_l.c				\
				deci_conv_ll.c				\
				deci_conv_noclong.c			\
				deci_conv_z.c				\
				ft_atoi.c					\
				ft_bzero.c					\
				ft_memalloc.c				\
				ft_printf.c					\
				ft_putchar.c				\
				ft_putnbr.c					\
				ft_putstr.c					\
				ft_strlen.c					\
				ft_strncpy.c				\
				ftp_putnbr.c				\
				hexa_conv_h.c				\
				hexa_conv_hh.c				\
				hexa_conv_j.c				\
				hexa_conv_l.c				\
				hexa_conv_ll.c				\
				hexa_conv_noclong.c			\
				hexa_conv_z.c				\
				mem_conv.c					\
				octal_conv_h.c				\
				octal_conv_hh.c				\
				octal_conv_j.c				\
				octal_conv_l.c				\
				octal_conv_ll.c				\
				octal_conv_noclong.c		\
				octal_conv_z.c				\
				pf_call_printer.c			\
				pf_char_conv.c				\
				pf_deci_conv.c				\
				pf_fill_data.c				\
				pf_hexa_conv.c				\
				pf_is.c						\
				pf_mem_conv.c				\
				pf_octal_conv.c				\
				pf_percent_conv.c			\
				pf_print_line.c				\
				pf_put.c					\
				pf_putascii.c				\
				pf_putcharuni.c				\
				pf_putdeci_h.c				\
				pf_putdeci_hh.c				\
				pf_putdeci_j.c				\
				pf_putdeci_l.c				\
				pf_putdeci_ll.c				\
				pf_putdeci_z.c				\
				pf_puthexa.c				\
				pf_puthexa_h.c				\
				pf_puthexa_hh.c				\
				pf_puthexa_j.c				\
				pf_puthexa_l.c				\
				pf_puthexa_ll.c				\
				pf_puthexa_z.c				\
				pf_putmem_noclong.c			\
				pf_putoctal.c				\
				pf_putoctal_h.c				\
				pf_putoctal_hh.c			\
				pf_putoctal_j.c				\
				pf_putoctal_l.c				\
				pf_putoctal_ll.c			\
				pf_putoctal_z.c				\
				pf_putstruni.c				\
				pf_putunsigned_h.c			\
				pf_putunsigned_hh.c			\
				pf_putunsigned_j.c			\
				pf_putunsigned_l.c			\
				pf_putunsigned_ll.c			\
				pf_putunsigned_noclong.c	\
				pf_putunsigned_z.c			\
				pf_string_conv.c			\
				pf_unsigned_conv.c			\
				pf_until_conv.c				\
				string_conv_l.c				\
				string_conv_noclong.c		\
				unsigned_conv_h.c			\
				unsigned_conv_hh.c			\
				unsigned_conv_j.c			\
				unsigned_conv_l.c			\
				unsigned_conv_ll.c			\
				unsigned_conv_noclong.c		\
				unsigned_conv_z.c			\

OBJ_NAME		=	$(SRC:.c=.o)
OBJ_PATH		=	obj/
OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
NAME			=	libftprintf.a
FLAGS			=	-Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir -p obj
	gcc -c $(FLAGS) -I includes $< -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

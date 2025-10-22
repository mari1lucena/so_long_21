# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlucena- <mlucena-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 18:12:33 by mlucena-          #+#    #+#              #
#    Updated: 2025/05/12 11:27:30 by mlucena-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
OBJ_DIR = ./obj
SRC = ft_printf.c ft_putchar.c ft_putadress.c ft_hexa.c ft_putnbr.c ft_putstr.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $@ $(OBJ)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@echo "removing $(OBJ_DIR)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "removedo $(NAME)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 20:55:50 by mlucena-          #+#    #+#              #
#    Updated: 2025/10/22 15:19:00 by mlucena-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do executável
NAME = so_long

# Arquivos fonte
SRCS = srcs/main.c \
	   srcs/check_map.c \
	   srcs/flood_fill.c \
	   srcs/check_fd.c \
	   srcs/free.c \
	   srcs/parsing_map.c \
	   srcs/utils_base.c \
	   srcs/utils.c \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c

# Objetos
OBJS = $(SRCS:.c=.o)

# Diretórios
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
PRINTF_DIR = printf

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm

# Regra principal
all: $(NAME)

# Compilar libft
$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

# Compilar printf
$(PRINTF_DIR)/libftprintf.a:
	@make -C $(PRINTF_DIR)

# Compilar cada arquivo objeto
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilado: $<"

# Linkar os objetos no executável
$(NAME): $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "so_long compilado com sucesso!"

# Limpar objetos
clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@rm -f $(OBJS)
	@echo "Arquivos objetos limpos"

# Limpar tudo
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@echo "Executável e bibliotecas removidos"

# Recompilar
re: fclean all

.PHONY: all clean fclean re
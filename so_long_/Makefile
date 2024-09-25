# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 13:15:01 by fatigarc          #+#    #+#              #
#    Updated: 2024/08/23 06:13:37 by fatigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
AR = ar -rcs
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lXext -lX11 -lm -lbsd
MLX_PATH = mlx_linux1/libmlx.a
LIBFT_PATH = libft2/libft.a
INCLUDES = -I/usr/include -Imlx_linux -Ilibft2

SRC = game/init.c game/message.c game/player_move.c game/draw.c game/hook.c parsing/parsing.c parsing/position.c parsing/valid_map.c main.c free/free.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_PATH):
	@$(MAKE) -C libft2

$(MLX_PATH):
	@$(MAKE) -C mlx_linux1

$(NAME): $(OBJ) $(LIBFT_PATH) $(MLX_PATH) 
	$(CC) $(CFLAGS) $(OBJ) $(MLX_PATH) $(MLX_FLAGS) $(LIBFT_PATH) -o $(NAME) 

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o  $@

clean:
	@$(MAKE) -C libft2 clean
	@$(MAKE) -C mlx_linux1 clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft2 fclean
	rm -f $(MLX_PATH)
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re

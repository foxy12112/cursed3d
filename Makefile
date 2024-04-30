# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelhaj- <mbelhaj-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 03:01:31 by mbelhaj-          #+#    #+#              #
#    Updated: 2024/04/30 17:46:07 by mbelhaj-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CFLAGS = -O3 -ffast-math -Wall -Wextra -Werror
CC = cc

MLX_PATH = ./MLX42/build
MLX_LIB = $(MLX_PATH)/libmlx42.a
MLX_INC = $(MLX_PATH)

LIBFT = ./libft
LIBFT_LIB = $(LIBFT)/libft.a

LIBS = -L$(MLX_PATH) -lmlx42 -L/Users/$(USER)/.brew/opt/glfw/lib -lglfw -lm -ldl -pthread \
	-framework Cocoa -framework OpenGL -framework IOKit

SRCS = main.c free_all.c ./parse/ft_open_map.c ./parse/ft_get_text.c ./parse/ft_get_fc.c \
	./parse/ft_check.c\
	./parse/ft_check2.c\
	./parse/ft_utils.c\
	./raycasting/get_png.c\
	./raycasting/player_position.c\
	./raycasting/keys.c\
	./raycasting/raycast.c\
	./raycasting/raycasting2.c\
	./raycasting/raycasting3.c\
	./raycasting/utils.c\

OBJS = $(SRCS:.c=.o)

all: MLX42 $(NAME)
	@echo "   ______________    ____  ______"
	@echo "  / ___/_  __/   |  / __ \/_  __/"
	@echo "  \__ \ / / / /| | / /_/ / / /"
	@echo " ___/ // / / ___ |/ _, _/ / /"
	@echo "/____//_/ /_/  |_/_/ |_| /_/"

MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT_LIB) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_INC) -I$(LIBFT) -c -o $@ $<

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re: fclean all

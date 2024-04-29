# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 03:01:31 by mbelhaj-          #+#    #+#              #
#    Updated: 2024/04/29 21:06:08 by rallouan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CFLAGS = -O3 -ffast-math -Wall -Wextra -Werror
CC = cc

MLX = MLX/libmlx42.a
FLAG_MLX = -framework Cocoa -framework OpenGL -framework IOKit -lglfw
INCLUDE = -I/Users/${USER}/.brew/Cellar/glfw/3.4/include/GLFW
LIB = -L/Users/${USER}/.brew/Cellar/glfw/3.4/lib
LIBFT = ./libft
LIBFT_LIB = $(LIBFT)/libft.a

LIBS =  -L/Users/$(USER)
	

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

all: $(NAME)
	@echo "   ______________    ____  ______"
	@echo "  / ___/_  __/   |  / __ \/_  __/"
	@echo "  \__ \ / / / /| | / /_/ / / /"
	@echo " ___/ // / / ___ |/ _, _/ / /"
	@echo "/____//_/ /_/  |_/_/ |_| /_/"



$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(FLAG_MLX) $(MLX) -o $@ $(OBJS) $(LIBFT_LIB) $(LIB) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS)  -I$(LIBFT) -c -o $@ $<

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re: fclean all


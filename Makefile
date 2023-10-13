# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 17:54:42 by jbadaire          #+#    #+#              #
#    Updated: 2023/01/17 17:54:46 by jbadaire         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = so_long.out
MAKE_LIBFT = make -C libft

MLX = minilibx-linux/libmlx_Linux.a
MAKE_MLX = make -C minilibx-linux

MLX_FLAGS = -L./minilibx-linux -l:libmlx.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRCS =  main.c				\
		collectible_utils.c \
		frees.c				\
		maps_utils.c		\
		player.c			\
		rectangle_check.c	\
		utils.c				\
		graphics_utils.c	\
		location_utils.c	\
		textures_utils.c	\
		errors_utils.c		\

LIBFT_FLAGS = -L./libft -l:libft.a
OBJ_DIRECTORY = ./.obj/


CC = cc

FLAGS = -c -Wall -Wextra -Werror -g

INCLUDES = ./headers/so_long.h

OBJS = $(addprefix $(OBJ_DIRECTORY), $(SRCS:.c=.o))

$(NAME): $(OBJ_DIRECTORY) $(OBJS)
	$(MAKE_MLX)
	$(MAKE_LIBFT)
	$(CC) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIRECTORY)%.o: %.c
	mkdir -p minilibx-linux
	$(CC) $(FLAGS) $< -o $@

$(OBJ_DIRECTORY):
	mkdir -p $(OBJ_DIRECTORY)

all : $(NAME)

clean :
	$(RM) $(NAME)
	rm -rf $(OBJ_DIRECTORY)

fclean : clean
	rm -rf $(NAME)

re : fclean all
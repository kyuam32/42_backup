# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 18:59:19 by namkyu            #+#    #+#              #
#    Updated: 2021/04/11 16:33:17 by namkyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror
LIBS = -L ./ -lmlx -framework OpenGL -framework AppKit

NAME = cub3D
MLX = libmlx.dylib
MLX_DIR = ./new_minilbx
LIBFT = libft.a
LIBFT_DIR = ./lib/1.libft

FILE = src/main \
		src/utils \
		src/keypress \
		src/ray_cast \
		src/ray_calculate \
		src/draw_window \
		src/draw_basic \
		src/mini_map \
		src/parse_cub_data \
		src/map_create \
		src/map_dfs \
		src/sprite \
		src/exit \
		src/allocate \
		src/bitmap \
		src/valid_check \

SRC = $(addsuffix .c, $(FILE))
OBJ = $(addsuffix .o, $(FILE))

all : $(NAME)

$(NAME) : $(OBJ) $(MLX) $(LIBFT)
	$(CC) ${CFLAGS} -o ${NAME} $(OBJ) $(LIBFT) $(MLX) ${LIBS}

$(MLX) :
	$(MAKE) -C ${MLX_DIR}
	mv ${MLX_DIR}/$@ ./

$(LIBFT) :
	$(MAKE) -C ${LIBFT_DIR}
	mv ${LIBFT_DIR}/$@ ./

clean :
	rm -rf $(OBJ)
	$(MAKE) -C ${MLX_DIR} clean
	$(MAKE) -C ${LIBFT_DIR} clean

fclean : clean
	rm -rf $(NAME) $(MLX) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
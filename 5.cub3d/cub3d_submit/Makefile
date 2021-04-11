# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 18:59:19 by namkyu            #+#    #+#              #
#    Updated: 2021/04/10 18:57:34 by namkyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror -g -fsanitize=address
LIBS = -L ./ -lmlx -framework OpenGL -framework AppKit

NAME = cub3D
MLX = libmlx.dylib
LIBFT = libft.a

FILE = main \
		utils \
		keypress \
		ray_cast \
		ray_calculate \
		draw_window \
		draw_basic \
		mini_map \
		parse_cub_data \
		map_create \
		map_dfs \
		sprite \
		exit \
		allocate \
		bitmap \
		valid_check \

SRC = $(addsuffix .c, $(FILE))
OBJ = $(addsuffix .o, $(FILE))

all : $(NAME)

$(NAME) : $(OBJ) $(MLX) $(LIBFT)
	$(CC) ${CFLAGS} -o ${NAME} $(OBJ) $(LIBFT) ${LIBS}

$(MLX) :
	$(MAKE) -C ./new_minilbx
	mv ./new_minilbx/$@ ./

$(LIBFT) :
	$(MAKE) -C ./1.libft
	mv ./1.libft/$@ ./

clean :
	rm -rf $(OBJ)
	$(MAKE) -C ./new_minilbx clean
	$(MAKE) -C ./1.libft clean

fclean : clean
	rm -rf $(NAME) $(MLX) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
.SILENT : $(MLX)
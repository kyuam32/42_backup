# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 18:59:19 by namkyu            #+#    #+#              #
#    Updated: 2021/04/06 22:07:29 by namkyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror -g
LIBS = -L ./ -lmlx -framework OpenGL -framework AppKit
MLX = libmlx.dylib
LIBFT = libft.a

NAME = cub3D
FILE = main \
		utils \
		ray_cast \
		draw_pixcel \
		mini_map \
		data_parse \
		map_parse \
		map_dfs \
		sprite \
		3.GNL/get_next_line \
		3.GNL/get_next_line_utils \

SRC = $(addsuffix .c, $(FILE))
OBJ = $(addsuffix .o, $(FILE))

all : $(NAME)
	./$(NAME)

$(NAME) : $(OBJ) $(MLX) $(LIBFT)
	$(CC) ${CFLAGS} -o ${NAME} $(OBJ) $(LIBFT) ${LIBS}

$(MLX) :
	$(MAKE) -C ./new_minilbx
	cp ./new_minilbx/$@ ./

$(LIBFT) :
	$(MAKE) -C ./1.libft
	cp ./1.libft/$@ ./

clean :
	rm -rf $(OBJ)

fclean : clean
	$(MAKE) -C ./new_minilbx clean
	$(MAKE) -C ./1.libft clean
	rm -rf $(NAME) $(MLX) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
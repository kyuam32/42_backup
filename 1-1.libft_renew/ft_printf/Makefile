# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 17:16:58 by namkyu            #+#    #+#              #
#    Updated: 2021/02/25 12:38:37 by namkyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar
AFLAGS = rcs

FILES = ft_printf\
		printf_parse_part_1\
		printf_parse_part_2\
		printf_data_utils\
		printf_display_utils
LIB_DIR = ./libft
INC_DIR = -I ./include -I ./libft
SRC_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ_DIR = ./
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR) everything
	cp $(LIB_DIR)/libft.a $@
	$(AR) $(AFLAGS) $@ $^

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS) $(INC_DIR)

all: $(NAME)

clean:
	-rm -rf $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean

fclean:
	-rm -rf $(OBJS) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY : all clean fclean re
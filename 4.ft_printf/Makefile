# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/05 17:16:58 by namkyu            #+#    #+#              #
#    Updated: 2021/02/23 14:39:25 by namkyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST = a.out

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar
AFLAGS = rcs

FILES = ft_printf\
		printf_parse_part_A\
		printf_parse_part_B\
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

	# make -C (dir) flag는 현재 directory에서 make 하지 않고 (dir)로 지정된 디렉토리에서 make 를 실행함

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS) $(INC_DIR)

	#remind! -c .o compile
	#        -I header direcroty
	#        -o output name

$(TEST):
	$(CC) $(SRCS) ./libft/libft.a $(INC_DIR) -o $@

all: $(NAME)

me:	$(TEST)

meclean:
	-rm -rf $(OBJS) $(TEST)

again: meclean me

clean:
	-rm -rf $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean

fclean:
	-rm -rf $(OBJS) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY : all clean fclean re me meclean

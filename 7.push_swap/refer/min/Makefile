# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/15 16:34:45 by yujo              #+#    #+#              #
#    Updated: 2021/03/09 02:32:52 by minckim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap checker

CHECKER = checker
PUSHSWAP = push_swap

CC = gcc

FLAG = -Wall -Wextra -Werror -g

# FLAG = -g

# -----------------------------------------------------------------------------
# File names
# -----------------------------------------------------------------------------

UTIL_FILE = \
	util\
	sort\
	print_num\
	util_stack1\
	util_stack2\
	util_stack3\
	util_stack4

PUSHSWAP_FILE = \
	$(UTIL_FILE)\
	instructions1\
	instructions2\
	instructions3\
	solve_pivot\
	solve_stack_rewind\
	solve_a\
	solve_case3a\
	solve_b\
	solve_case3b\
	push_swap

CHECKER_FILE = \
	$(UTIL_FILE)\
	checker

# -----------------------------------------------------------------------------
# Basic settings
# -----------------------------------------------------------------------------
DIR_SRCS = ./srcs/
DIR_OBJS = ./objs/

CHECKER_SRCS = $(addprefix $(DIR_FILE), $(addsuffix .c, $(CHECKER_FILE)))
CHECKER_OBJS = $(addprefix $(DIR_OBJS), $(addsuffix .o, $(CHECKER_FILE)))

PUSHSWAP_SRCS = $(addprefix $(DIR_FILE), $(addsuffix .c, $(PUSHSWAP_FILE)))
PUSHSWAP_OBJS = $(addprefix $(DIR_OBJS), $(addsuffix .o, $(PUSHSWAP_FILE)))

LIBFT_DIR = ./libft/
LIBFT = libft.a

INCLUDE = $(DIR_SRCS)
RM = rm -rf

# -----------------------------------------------------------------------------
# Rules
# -----------------------------------------------------------------------------
all : $(NAME) random_numbers

$(LIBFT) :
	@make -C $(LIBFT_DIR)

$(DIR_OBJS):
	@mkdir $(DIR_OBJS)

$(CHECKER) : $(LIBFT) $(DIR_OBJS) $(CHECKER_OBJS)
	@$(CC) $(FLAG) -o $(CHECKER) $(CHECKER_OBJS) -lft -L$(LIBFT_DIR)

$(PUSHSWAP) : $(LIBFT) $(DIR_OBJS) $(PUSHSWAP_OBJS)
	@$(CC) $(FLAG) -o $(PUSHSWAP) $(PUSHSWAP_OBJS) -lft -L$(LIBFT_DIR)


random_numbers :
	@echo "random number creator..."
	@make -C ./tester/

$(DIR_OBJS)%.o : $(DIR_SRCS)%.c
	$(CC) $(FLAG) -c $< -o $@

re : fclean $(NAME)

clean :
	@echo $(YELLOW)"Removing push_swap object files..."$(WHITE)
	@$(RM) $(DIR_OBJS)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	@echo $(YELLOW)"Removing libft.a..."$(WHITE)
	@$(RM) $(LIBFT_DIR)libft.a
	@echo $(YELLOW)"Removing push_swap and checker..."$(WHITE)
	@$(RM) $(NAME)
	@echo $(YELLOW)"Removing push_swap and checker..."$(WHITE)
	@make fclean -C ./tester/

norm:
	norminette $(DIR_SRCS)*.c $(DIR_SRCS)*.h
	norminette $(LIBFT_DIR)*.c

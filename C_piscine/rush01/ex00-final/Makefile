# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeryul <jaeryul@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/09 21:01:10 by jaeryul           #+#    #+#              #
#    Updated: 2020/08/09 22:46:29 by jaeryul          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = rush-01
OBJECTS = main.o input.o memory.o map.o solve.o condition_check.o

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

main.o : main.c main.h
	$(CC) $(CFLAGS) -c $^

input.o : input.c main.h
	$(CC) $(CFLAGS) -c $^

memory.o : memory.c main.h
	$(CC) $(CFLAGS) -c $^

map.o : map.c main.h
	$(CC) $(CFLAGS) -c $^

solve.o : solve.c main.h
	$(CC) $(CFLAGS) -c $^

condition_check.o :condition_check.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJECTS) *.gch

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

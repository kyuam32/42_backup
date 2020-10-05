# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/21 12:24:13 by nlee              #+#    #+#              #
#    Updated: 2020/08/21 12:35:23 by nlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Wall -Werror

TARGET = do-op

INC = nlee.h
OBJ = cal.o function.o main.o
SRC = cal.c function.c main.c

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS)  -o $@ $(OBJ)

%o : %.c
	$(CC) $(CFLAGS) $< -o $@ $(INC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(TARGET)

re : fclean all

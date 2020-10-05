# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 21:31:28 by nlee              #+#    #+#              #
#    Updated: 2020/08/20 23:42:22 by nlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

SRCDIR = srcs
INCDIR = includes

TARGET = libft.a
SOURCES = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INCDIR)

$(TARGET): $(OBJECTS)
	ar cr $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

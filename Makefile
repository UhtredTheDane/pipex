# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agengemb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 05:17:18 by agengemb          #+#    #+#              #
#    Updated: 2023/01/12 03:16:00 by agengemb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
LIB1 = ./ft_printf/libftprintf.a
SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB1)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 
	
$(LIB1):
	make -C ft_printf

clean:
	make -C ft_printf clean
	rm -f $(LIB1)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

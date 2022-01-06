# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 11:38:14 by jhermon-          #+#    #+#              #
#    Updated: 2021/12/29 14:29:46 by jhermon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = long

SRC = *.c

CC = gcc

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -Imlx

LIBX = -Lmlx -lmlx -lz -framework OpenGL -framework AppKit

all: $(NAME) 

$(NAME): $(OBJ)
		 $(CC) $(FLAGS) $(OBJ) $(LIBX) -o $(NAME)
		 rm $(OBJ)

$(OBJ): $(SRC)
		$(CC) $(FLAGS) -c $(SRC)

exe: all
		./$(NAME)

clean: 
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

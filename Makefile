# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 15:25:04 by jhermon-          #+#    #+#              #
#    Updated: 2021/12/09 15:34:47 by jhermon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= 	so_long

CFLAGS		= 	-Wall -Werror -Wextra -Imlx

OPTIONS		=	-Lmlx -lmlx -lz -framework OpenGL -framework AppKit

CC			= 	gcc

RM			= 	rm -f

PTC			=	main.c

PTO			=	$(PTC:%.c=%.o)

all:		$(NAME)

$(NAME):	$(PTO)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(NAME) $(PTO)

clean:		
	$(RM) $(PTO)

fclean:
	$(RM) $(NAME)
	
re:			clean fclean

.PHONY:		all clean fclean re

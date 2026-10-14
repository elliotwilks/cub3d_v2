# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elwilks <elwilks@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/13 13:03:23 by elwilks           #+#    #+#              #
#    Updated: 2026/10/14 17:21:46 by elwilks          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NOTE
# Running "make" in the terminal lauches the Makefile and searches for  the
# first "command" in the make file. The first command is usually "all"

#::::::::::::::::::::	VARIABLES	::::::::::::::::::::::::

NAME= a.out

CC= cc

CFLAGS= -Wall -Wextra -Werror

SRC= main.c utils.c libft.c parse.c build_player.c

INCLUDE= -IMLX42/include/MLX42/ -IMLX42/include

MLX_LIBRARY= MLX42/build/libmlx42.a

MLX_FLAGS= -ldl -lglfw -pthread -lm

#::::::::::::::::::::	COMMANDS	::::::::::::::::::::::::

all:
	$(CC) $(CFLAGS) $(SRC) $(INCLUDE) $(MLX_LIBRARY) $(MLX_FLAGS)

clean:
	rm -rf a.out

re: clean all

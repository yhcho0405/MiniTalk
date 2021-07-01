# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:49:37 by youncho           #+#    #+#              #
#    Updated: 2021/07/02 00:57:51 by youncho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft all clean fclean re

NAME_SV = server
NAME_CL = client

SRCS_SV =	server.c	\

SRCS_CL =	client.c	\

GCC_FLAG = -Wall -Werror -Wextra #-g -fsanitize=address
CC = gcc $(GCC_FLAG)

OBJS_SV = $(SRCS_SV:.c=.o)
OBJS_CL = $(SRCS_CL:.c=.o)

all: $(NAME_SV) $(NAME_CL)

libft:
	make bonus -C libft/

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME_SV): libft $(OBJS_SV)
	$(CC) -o $@ $(OBJS_SV) -Llibft -lft -I./

$(NAME_CL): libft $(OBJS_CL)
	$(CC) -o $@ $(OBJS_CL) -Llibft -lft -I./

clean:
	rm -f *.o
	make -C libft/ clean

fclean: clean
	rm -f $(NAME_SV) $(NAME_CL)
	make -C libft/ fclean

re: fclean all

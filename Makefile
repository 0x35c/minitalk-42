# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2022/10/22 22:50:01 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

SRCS = server.c

CC = @gcc

CFLAGS = -g -Wall -Wextra -Werror

LIBS = -Lprintf -lftprintf

OBJ = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: all clean

.PHONY: all clean fclean re

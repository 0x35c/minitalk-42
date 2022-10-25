# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2022/10/25 00:00:50 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERV_SRC = server.c

CLIENT_SRC = client.c

CC = @gcc

CFLAGS = -g -Wall -Wextra -Werror

LIBS = -Lprintf -lftprintf -Llibft -lft
SERV_OBJ = $(SERV_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: server client

client: ${CLIENT_OBJ}
	$(CC) -o client $(CLIENT_OBJ) $(LIBS)

server: ${SERV_OBJ}
	$(CC) -o server $(SERV_OBJ) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -f $(CLIENT_OBJ) $(SERV_OBJ)

fclean: clean
	@rm -f client server

re: all clean

.PHONY: all clean fclean re

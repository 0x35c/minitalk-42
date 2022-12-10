# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulayus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:40:22 by ulayus            #+#    #+#              #
#    Updated: 2022/12/10 15:09:37 by ulayus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client

SRC_C = mandatory/client.c 
SRC_S = mandatory/server.c

SRC_CB = bonus/client_bonus.c 
SRC_SB = bonus/server_bonus.c

CC = @clang

CFLAGS = -g -Wall -Wextra -Werror
LIBS = -Llibft -lft -Llibft/printf -lftprintf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJ_CB = $(SRC_CB:.c=.o)
OBJ_SB = $(SRC_SB:.c=.o)

all: make_libft ${NAME_S} ${NAME_C}

bonus: make_libft ${NAME_S}_B ${NAME_C}_B

make_libft: 
	@make -C libft > /dev/null
	@printf '\x1b[38;2;50;205;50mLibft compiled 🤓\n\x1b[0m'

${NAME_C}: ${OBJ_C}
	$(CC) ${OBJ_C} -o ${NAME_C} $(LIBS)
	@printf '\x1b[38;2;50;205;50mMinitalk client compiled 🤓\n\x1b[0m'

${NAME_S}: ${OBJ_S}
	$(CC) ${OBJ_S} -o ${NAME_S} $(LIBS)
	@printf '\x1b[38;2;50;205;50mMinitalk server compiled 🤓\n\x1b[0m'

${NAME_C}_B: ${OBJ_CB}
	$(CC) ${OBJ_C} -o ${NAME_C} $(LIBS)
	@printf '\x1b[38;2;50;205;50mBonus Minitalk client compiled 🤓\n\x1b[0m'

${NAME_S}_B: ${OBJ_SB}
	$(CC) ${OBJ_SB} -o ${NAME_S} $(LIBS)
	@printf '\x1b[38;2;50;205;50mBonus Minitalk server compiled 🤓\n\x1b[0m'

clean:
	@rm -f $(OBJ_C)
	@rm -f $(OBJ_S)
	@printf '\e[5m❌ \e[0m\x1b[38;2;255;140;0mObjects removed\x1b[0m\e[5m ❌\n\e[0m'

fclean: clean
	@rm -f ${NAME_C} 
	@rm -f ${NAME_S} 
	@printf '\e[5m🚨 \e[0m\x1b[38;2;200;0;20mBinary removed\x1b[0m\e[5m 🚨\n\e[0m'

clean_b:
	@rm -f $(OBJ_CB)
	@rm -f $(OBJ_SB)
	@printf '\e[5m❌ \e[0m\x1b[38;2;255;140;0mBonus objects removed\x1b[0m\e[5m ❌\n\e[0m'

fclean_b: clean_b
	@rm -f ${NAME_S}
	@rm -f ${NAME_C}
	@printf '\e[5m🚨 \e[0m\x1b[38;2;200;0;20mBonus binary removed\x1b[0m\e[5m 🚨\n\e[0m'

re: fclean all

re_b: fclean_b bonus

.PHONY: all clean fclean re bonus clean_b fclean_b re_b

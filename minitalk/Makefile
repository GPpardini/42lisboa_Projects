# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 16:38:49 by gpardini          #+#    #+#              #
#    Updated: 2023/05/06 17:49:09 by gpardini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME		= 	server

CLIENT_NAME		=	client

BONUS_SERVER	=	bserver

BONUS_CLIENT	=	bclient

CC				= 	cc #-g -fsanitize=address

CFLAGS			= 	-Wall -Wextra -Werror -g

RM				= 	rm -f

SRC_SERV		=	server.c utils.c

SRC_CLIENT		=	client.c utils.c

SRC_BSERV		=	bonus_server.c utils.c

SRC_BCLIENT		=	bonus_client.c utils.c

OBJS			= 	client server bclient bserver

all: 		$(SERVER_NAME) $(CLIENT_NAME) $(BONUS_SERVER) $(BONUS_CLIENT)

$(SERVER_NAME):	$(SRC_SERV)
			@$(CC) $(CFLAGS) $(SRC_SERV) -o $(SERVER_NAME)

$(CLIENT_NAME):	$(SRC_CLIENT)
			@$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(CLIENT_NAME)

bonus:		$(BONUS_SERVER) $(BONUS_CLIENT)

$(BONUS_SERVER):	$(SRC_BSERV)
			@$(CC) $(CFLAGS) $(SRC_BSERV) -o $(BONUS_SERVER)

$(BONUS_CLIENT):	$(SRC_BCLIENT)
			@$(CC) $(CFLAGS) $(SRC_BCLIENT) -o $(BONUS_CLIENT)

clean:
			@$(RM) $(OBJS)

fclean: clean
			@$(RM) $(NAME)

re: fclean all

norm :
			@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

.PHONY: 	all re clean fclean m bonus

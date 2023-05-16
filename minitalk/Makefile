# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 16:38:49 by gpardini          #+#    #+#              #
#    Updated: 2023/05/16 20:18:06 by gpardini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME		= 	server

CLIENT_NAME		=	client

CC				= 	cc

CFLAGS			= 	-Wall -Wextra -Werror -g

RM				= 	rm -f

SRC_SERV		=	server.c utils.c

SRC_CLIENT		=	client.c utils.c

OBJS			= 	client server bclient bserver

all: 		$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):	$(SRC_SERV)
			@$(CC) $(CFLAGS) $(SRC_SERV) -o $(SERVER_NAME)

$(CLIENT_NAME):	$(SRC_CLIENT)
			@$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(CLIENT_NAME)

clean:
			@$(RM) $(OBJS)

fclean: clean
			@$(RM) $(NAME)

re: fclean all

norm :
			@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

.PHONY: 	all re clean fclean m 

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 16:38:49 by gpardini          #+#    #+#              #
#    Updated: 2023/05/18 18:45:09 by gpardini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME		= 	server

CLIENT_NAME		=	client

CC				= 	cc

CFLAGS			= 	-Wall -Wextra -Werror  -g -fsanitize=address

RM				= 	rm -f

OBJ_SERV		= 	server.o utils.o

OBJ_CLIENT		= 	client.o utils.o

all: 		$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):	$(OBJ_SERV)
			@$(CC) $(CFLAGS) $(OBJ_SERV) -o $(SERVER_NAME)

$(CLIENT_NAME):	$(OBJ_CLIENT)
			@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT_NAME)

clean:
			@$(RM) $(OBJ_SERV) $(OBJ_CLIENT)

fclean: clean
			@$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

norm :
			@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

.PHONY: 	all re clean fclean m 

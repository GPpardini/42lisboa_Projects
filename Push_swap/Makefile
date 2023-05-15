# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 19:18:09 by gpardini          #+#    #+#              #
#    Updated: 2023/05/08 11:28:33 by gpardini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM_NAME	= 	push_swap

CC				= 	cc -g -fsanitize=address

CFLAGS			= 	-Wall -Wextra -Werror -g

RM				= 	rm -f

SRC				=	push_swap.c includes.c

OBJS			= 	push_swap *.o

all: 		$(PROGRAM_NAME)

$(PROGRAM_NAME):	$(SRC)
			@$(CC) $(CFLAGS) $(SRC) -o $(PROGRAM_NAME)

clean:
			@$(RM) $(OBJS)

fclean: clean
			@$(RM) $(PROGRAM_NAME)

re: fclean all

run: re
			./$(PROGRAM_NAME)

.PHONY: 	all re clean fclean run

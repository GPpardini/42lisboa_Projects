# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 19:18:09 by gpardini          #+#    #+#              #
#    Updated: 2023/05/22 17:01:35 by gpardini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM_NAME	= 	push_swap

CC				= 	cc 

CFLAGS			= 	-Wall -Wextra -Werror #-g -fsanitize=address

RM				= 	rm -f

LIB				=	pushswap.h

SRC				=	libft_usuals/*.c list_functions/*.c push_swap.c utils.c sorting.c

OBJS			=	$(SRCS:.c=.o)

all: 		$(PROGRAM_NAME)

$(PROGRAM_NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(SRC) -o $(PROGRAM_NAME)

clean:
			@$(RM) $(OBJS)

fclean: clean
			@$(RM) $(PROGRAM_NAME)

re: fclean all

run: re
			./push_swap "1 2 3 4 5 6 7 8 9"
run1: re
			./push_swap "1 2 3 4 a 6 7 8 9"
run3: re
			./push_swap "3 1 2"

.PHONY: 	all re clean fclean run

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 19:18:09 by gpardini          #+#    #+#              #
#    Updated: 2023/06/09 19:06:14 by gpardini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM_NAME	= 	push_swap

CC				= 	cc

CFLAGS			= 	-Wall -Wextra -Werror -g #-fsanitize=address

RM				= 	rm -f

LIB				=	pushswap.h

SRC				=	libft_usuals/ft_atoi.c libft_usuals/ft_itoa.c libft_usuals/ft_strcmp.c libft_usuals/ft_strlcpy.c \
					libft_usuals/ft_substr.c libft_usuals/ft_isdigit.c libft_usuals/ft_split.c libft_usuals/ft_strdup.c \
					libft_usuals/ft_strlen.c list_and_moves/p.c list_and_moves/r.c list_and_moves/rr.c list_and_moves/s.c \
					list_utils.c push_swap.c sort_3.c sort_4.c sort_5.c sort_radix.c utils.c is_rep.c

OBJS			=	$(SRC:.c=.o)

all: 			$(PROGRAM_NAME)

$(PROGRAM_NAME): $(SRC)
			@$(CC) $(CFLAGS) $(SRC) -o $(PROGRAM_NAME)

clean:
			@$(RM) $(OBJS)

fclean: clean
			@$(RM) $(PROGRAM_NAME)

re: fclean all

.PHONY: 	all re clean fclean run

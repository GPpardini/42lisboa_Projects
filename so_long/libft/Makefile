# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 21:04:02 by gpardini          #+#    #+#              #
#    Updated: 2023/07/10 21:05:22 by gpardini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =			get_next_line.c

NAME = libft.a
HDRS = libft.h
CC = cc
FLAGS = -Wall -Werror -Wextra
OBJS = $(SRC:.c=.o)

# ====================================================================================
# COLORS
# ====================================================================================

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHITE		:=	\033[1;37m
BOLD		:=	\033[1;1m

all: $(NAME)

%.o:%.c
	@cc -Wall -Wextra -Werror -o $@ -c $<

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "$(GREEN) [Success] Done the compilation Libft.$(BOLD)"

clean:
	@/bin/rm -f $(NAME)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 11:04:16 by jede-ara          #+#    #+#              #
#    Updated: 2023/07/06 14:22:41 by gpardini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =			ft_split.c get_next_line.c

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

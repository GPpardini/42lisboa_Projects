# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 19:53:58 by nfilipe-          #+#    #+#              #
#    Updated: 2023/06/20 18:44:13 by gpardini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# SAFEGUARDS

# to avoid problems with any 'SHELL'-named variable
SHELL	=	/bin/bash 

# to delete the default suffixes & define our suffix list
#.SUFIXES:					   
#.SUFIXES:	.a .c .h .o

################################################################################
# ARGUMENTS

# the name of the executable built by this Makefile
NAME 	=	so_long

# compiler (cc) & flags to be used
# '-O2' applies almost all of the supported optimization techniques that do \
not involve a tradeoff between program size and execution speed. This option \
generally increases the time needed to compile.
# '-I<dir>' adds the current directory to include search path for 'libft.h'
# 'DEBUG' flags will compile the code with debug symbols (-g) & detect memory \
access error such as use-after-free and memory leaks (-fsanitize=address)
CC		=	cc 
CFLAGS	=	-O2 -Wall -Werror -Wextra
#DEBUG	=	-g -fsanitize=address

# 'rm -rf' forced file removal (ignores nonexistent files and arguments), \
including directories and their contents, recursively (-r)
REMOVE	=	rm -rf

################################################################################
# SOURCES

# the complete list of the source files to be used
SRCS	=	getnextline/*.c utils/*.c libft_utils/*.c *.c
			
# the complete list of all the objects to be created
OBJECTS	=	$(SRCS:.c=.o)
 
# project's header file
INCLUDE	=	*.h getnextline/*.h

################################################################################
# RULES

# our default goal - it compiles the entire program
all:		$(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
			
$(NAME):	$(OBJECTS)
			@echo compiling \& linking sources
			@echo building $(NAME)
			$(CC) $(OBJECTS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# tells how to make ‘.o’ files from ‘.c’ files and makes all ‘.o’ files \
using this pattern rule also depend on libft.h
# '-c' preprocess, compile, and assemble only (i.e., don’t link)
# '-o' Direct output to the specified file.

clean:
			@echo removing all objects
			$(REMOVE) $(OBJECTS)

fclean:		clean
			@echo removing $(NAME)
			$(REMOVE) $(NAME)

re:			fclean $(NAME)

################################################################################
# SPECIAL RULES

info:	
			@echo Makefile for \'so_long\' v0.4.20.69.666.42
# A phony target is one that is not really the name of a file; rather it \
is just a name for a recipe to be executed when you make an explicit \
request.It mainly avoids a conflict with a file of the same name
.PHONY:		all clean fclean re info acknowledgments

# 'make' will not print the recipe used to remake those particular files \
before executing them.
.SILENT:	
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbadaire <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 17:54:42 by jbadaire          #+#    #+#              #
#    Updated: 2023/01/17 17:54:46 by jbadaire         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
RM				= rm -rf
CC				= gcc
FLAGS			= -Wall -Wextra -Werror -g3
OBJ_DIRECTORY	= ./.obj/
INCLUDE			= libft.h

SRCS			=				\
	ft_bzero.c					\
	ft_isalnum.c				\
	ft_isalpha.c				\
	ft_isascii.c				\
	ft_isdigit.c				\
	ft_isprint.c				\
	ft_memset.c					\
	ft_strlen.c					\
	ft_strlcat.c				\
	ft_tolower.c				\
	ft_toupper.c				\
	ft_strrchr.c				\
	ft_strchr.c 				\
	ft_strncmp.c				\
	ft_memchr.c					\
	ft_memcmp.c					\
	ft_strnstr.c				\
	ft_atoi.c					\
	ft_calloc.c					\
	ft_strdup.c					\
	ft_memcpy.c					\
	ft_memmove.c				\
	ft_strlcpy.c				\
	ft_substr.c					\
	ft_strjoin.c				\
	ft_strtrim.c				\
	ft_split.c					\
	ft_itoa.c					\
	ft_putchar_fd.c				\
	ft_putstr_fd.c				\
	ft_putendl_fd.c				\
	ft_striteri.c				\
	ft_strmapi.c				\
	ft_putnbr_fd.c				\
	ft_lstnew.c					\
	ft_lstadd_front.c			\
	ft_lstsize.c				\
	ft_lstlast.c				\
	ft_lstadd_back.c			\
	ft_lstdelone.c				\
	ft_lstclear.c				\
	ft_lstiter.c				\
	ft_base.c					\
	get_next_line.c				\
	get_next_line_utils.c		\
	ft_printf/ft_printf.c		\
	ft_printf/ft_args_handler.c	\
	ft_printf/ft_get_address.c	\
	ft_printf/ft_get_base16.c	\
	ft_printf/ft_get_char.c		\
	ft_printf/ft_get_integer.c	\
	ft_printf/ft_get_string.c	\

OBJS			= $(addprefix $(OBJ_DIRECTORY), $(SRCS:.c=.o))

all:	$(NAME)

so:		$(all)

$(NAME): $(OBJ_DIRECTORY) $(OBJS) $(INCLUDE)
	ar -rcs $(NAME) $(OBJS)

$(OBJ_DIRECTORY)%.o: %.c $(INCLUDE) Makefile
	$(CC) $(FLAGS) -I. -c $< -o $@

$(OBJ_DIRECTORY):
	mkdir -p $(OBJ_DIRECTORY) $(OBJ_DIRECTORY)ft_printf

clean:
	$(RM) $(OBJ_DIRECTORY)

fclean:	clean
	$(RM) $(NAME) *.out *.gch *.o .so

re:		fclean $(NAME)

.PHONY:	fclean clean all re

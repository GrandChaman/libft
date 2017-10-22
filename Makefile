# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bluff <bluff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/19 19:26:33 by bluff             #+#    #+#              #
#    Updated: 2017/10/22 23:53:30 by bluff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_bzero.c ft_isdigit.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c \
ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c \
ft_strdel.c ft_strnew.c ft_putchar.c ft_strclr.c ft_strequ.c ft_strnequ.c \
ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c \
ft_putnbr.c ft_putstr_fd.c ft_putstr.c
CFLAGS = -c -Wall -Wextra -Werror -O3
CC = gcc
LN = ar
LFLAGS = rc
LIBOPTIMIZER = ranlib
OBJS = $(SRCS:.c=.o)
NAME = libft.a

$(NAME):
	$(CC) $(CFLAGS) $(SRCS)
	$(LN) $(LFLAGS) $(NAME) $(OBJS)
	$(LIBOPTIMIZER) $(NAME)
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

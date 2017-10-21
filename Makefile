# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bluff <bluff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/19 19:26:33 by bluff             #+#    #+#              #
#    Updated: 2017/10/21 16:06:40 by bluff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FOLDER = src/
SRCS_NAMES = ft_memset.c
INCLUDE = includes
INCLUDE_FLAG = -I $(INCLUDE)
CFLAGS = -c -Wall -Wextra -Werror -O3
CC = gcc
LN = ar
LFLAGS = rc
LIBOPTIMIZER = ranlib
SRCS = $(addprefix $(SRC_FOLDER), $(SRCS_NAMES))
OBJS = $(SRCS_NAMES:.c=.o)
NAME = libft.a

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE_FLAG)
	$(LN) $(LFLAGS) $(NAME) $(OBJS)
	$(LIBOPTIMIZER) $(NAME)
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

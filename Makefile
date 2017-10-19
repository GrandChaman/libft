# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bluff <bluff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/19 19:26:33 by bluff             #+#    #+#              #
#    Updated: 2017/10/19 20:26:00 by bluff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FOLDER = src/
SRCS_NAMES = ft_memset.c
INCLUDE = include
INCLUDE_FLAG = -I $(INCLUDE)
CFLAGS = -c -Wall -Wextra -Werror -O3
CC = gcc
LN = ar
LFLAGS = rc
LIBOPTIMIZER = ranlib
SRCS = $(addprefix $(SRC_FOLDER), $(SRCS_NAMES))
OBJS = $(SRCS_NAMES:.c=.o)
BIN = libft.a

$(BIN):
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE_FLAG)
	$(LN) $(LFLAGS) $(BIN) $(OBJS)
	$(LIBOPTIMIZER) $(BIN)
all: $(BIN)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(BIN)

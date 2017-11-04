# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bluff <bluff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/19 19:26:33 by bluff             #+#    #+#              #
#    Updated: 2017/11/04 00:50:29 by bluff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define \n


endef
SRCS = btree_apply_by_level.c btree_apply_infix.c btree_apply_prefix.c \
btree_apply_suffix.c btree_create_node.c btree_insert_data.c \
btree_level_count.c btree_search_item.c ft_any.c ft_atoi.c ft_bzero.c \
ft_count_if.c ft_factorial.c ft_find_next_prime.c ft_foreach.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islowercase.c ft_isprime.c \
ft_isprint.c ft_issort.c ft_isuppercase.c ft_itoa.c ft_lst_at.c \
ft_lst_find.c ft_lst_foreach.c ft_lst_foreach_if.c ft_lst_last.c \
ft_lst_merge.c ft_lst_push_back.c ft_lst_push_front.c ft_lst_remove_if.c \
ft_lst_reverse.c ft_lst_size.c ft_lst_sort.c ft_lstadd.c ft_lstdel.c \
ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_map.c ft_memalloc.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
ft_memset.c ft_pow.c ft_print_memory.c ft_putchar.c ft_putchar_fd.c \
ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
ft_putstr_fd.c ft_range.c ft_sqrt.c ft_strcat.c ft_strchr.c ft_strclr.c \
ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
ft_swap.c ft_tolower.c ft_toupper.c
CFLAGS = -c -Wall -Wextra -Werror -O3
CC = gcc
LN = ar
LFLAGS = rc
LIBOPTIMIZER = ranlib
OBJS = $(SRCS:.c=.o)
NAME = libft.a
$(NAME):
	$(foreach SRC,$(SRCS),$(CC) $(CFLAGS) $(SRC)${\n})
	$(LN) $(LFLAGS) $(NAME) $(OBJS)
	$(LIBOPTIMIZER) $(NAME)
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

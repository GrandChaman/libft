# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bluff <bluff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/19 19:26:33 by bluff             #+#    #+#              #
#    Updated: 2017/11/14 14:08:08 by fle-roy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_any.c ft_atoi.c ft_bzero.c \
ft_count_if.c ft_factorial.c ft_find_next_prime.c ft_foreach.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islowercase.c ft_isprime.c \
ft_isprint.c ft_issort.c ft_isuppercase.c ft_itoa.c ft_lstat.c \
ft_lstfind.c ft_lstforeach.c ft_lstforeach_if.c ft_lstlast.c \
ft_lstmerge.c ft_lstpush_back.c ft_lstpush_front.c ft_lstremove_if.c \
ft_lstreverse.c ft_lstsize.c ft_lstsort.c ft_lstadd.c ft_lstdel.c \
ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_map.c ft_memalloc.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
ft_memset.c ft_pow.c ft_putchar.c ft_putchar_fd.c \
ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
ft_putstr_fd.c ft_range.c ft_sqrt.c ft_strcat.c ft_strchr.c ft_strclr.c \
ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
ft_swap.c ft_tolower.c ft_toupper.c ft_atoi_base.c ft_iswhitespace.c
CFLAGS = -c -Wall -Wextra -Werror
CC = gcc
LN = ar
LFLAGS = rc
LIBOPTIMIZER = ranlib
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME) libft.h
$(NAME): $(OBJS)
	@printf "\r\033[K[LIBFT] \033[0;32mLinking...\033[0m"
	@$(LN) $(LFLAGS) $(NAME) $?
	@printf "\r\033[K[LIBFT] \033[0;32mOptimizing...\033[0m"
	@$(LIBOPTIMIZER) $(NAME)
	@printf "\r\033[K[LIBFT] \033[0;32mDone!\033[0m\n"
%.o: %.c
	@printf "\r\033[K[LIBFT] \033[0;32mBuilding $<\033[0m"
	@$(CC) $(CFLAGS) $< -o $@
clean:
	@rm -f $(OBJS)
	@printf "[LIBFT] \033[1;31mCleaned .o!\033[0m\n"
fclean: clean
	@rm -f $(NAME)
	@printf "[LIBFT] \033[1;31mCleaned all!\033[0m\n"
re: fclean all

.PHONY: all clean fclean re

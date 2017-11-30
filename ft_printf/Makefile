# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bluff <bluff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/19 19:26:33 by bluff             #+#    #+#              #
#    Updated: 2017/11/30 13:55:41 by fle-roy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_utils.c ft_printf_string.c ft_printf_parser.c \
		ft_printf_parameters.c ft_printf_utils2.c ft_printf_numbers.c \
		ft_printf_utils3.c ft_printf_numbers_upper.c ft_printf_wstring.c \
		ft_printf_utils4.c ft_printf_extract_dynamic_param.c \
		ft_printf_numbers2.c
CFLAGS =-c -Wall -Wextra -Werror
INCLUDES = ft_printf.h ft_printf_format_list.h ft_printf_parser.h \
		ft_printf_utils.h
CC = gcc
LN = ar
LFLAGS = rc
LIBOPTIMIZER = ranlib
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
LIBFT = libft/libft.a

all: $(NAME)
$(NAME): $(LIBFT) $(OBJS) $(INCLUDES)
	@printf "\r\033[K[PRINTF] \033[0;32mLinking...\033[0m"
	@cp $(LIBFT) $(NAME)
	@$(LN) $(LFLAGS) $(NAME) $(OBJS)
	@printf "\r\033[K[PRINTF] \033[0;32mDone!\033[0m\n"
$(LIBFT):
	@$(MAKE) -C libft/
%.o: %.c
	@printf "\r\033[K[PRINTF] \033[0;32mBuilding $<\033[0m"
	@$(CC) $(CFLAGS) $< -o $@
clean:
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJS)
	@printf "[PRINTF] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)
	@printf "[PRINTF] \033[1;31mCleaned all!\033[0m\n"
re: fclean all
.PHONY: all clean fclean re

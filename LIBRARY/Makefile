# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allauren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 22:27:21 by allauren          #+#    #+#              #
#    Updated: 2017/12/07 09:05:32 by allauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = options.c print_numbers.c string.c   utils.c utils2.c\
		ft_itoabase.c  parsing.c  printf.c stritostr.c conv_base.c\
		utilshexa.c char.c hash.c wchar.c w_charmanager.c get_next_line.c

CFLAGS =-g3 -c -Wall -Wextra -Werror
FLAGS  = -g3 -Wall -Wextra -fsanitize=address 
INCLUDES = printf.h
CC = gcc
LIBOPTIMIZER = ranlib
OBJS = $(SRCS:.c=.o)
NAME = libft.a
LIBFT = libft/libft.a

all: $(NAME)
$(NAME): $(LIBFT) $(OBJS) $(INCLUDES)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@$(LIBOPTIMIZER) $(NAME)
$(LIBFT):
	@$(MAKE) -C libft/
%.o: %.c
	@$(CC) $(CFLAGS) $< -o $@
clean:
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
	# **************************************************************************** #

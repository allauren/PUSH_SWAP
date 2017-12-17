# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allauren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 22:27:21 by allauren          #+#    #+#              #
#    Updated: 2017/12/17 00:54:55 by allauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS1 =  doublelist.c list2del.c pushswapcommand.c \
		push_check.c push_swap.c utilspsw.c quicksort.c \
		utilpresort.c sort_small.c checkpsw.c push_check2.c \
		short_sort.c smart_sort.c ft_optimizer.c
SRCS2 =  checker.c doublelist.c list2del.c pushswapcommand.c \
		push_check.c utilspsw.c quicksort.c\
		utilpresort.c sort_small.c checkpsw.c push_check2.c ft_optimizer.c
CFLAGS =-g3 -c -Wall -Wextra -Werror
FLAGS  = -g3  -Wall -Wextra -Werror# -fsanitize=address
INCLUDES = INCLUDES
CC = gcc
LIBOPTIMIZER = ranlib
OBJS = $(SRCS:.c=.o)
NAME = push_swap
NAME2 = checker
LIBFT = lib/libft.a

all: $(NAME) $(NAME2)

$(NAME): $(LIBFT) $(INCLUDES) $(SRCS1)
	$(CC) $(FLAGS)  -I$(INCLUDES) $(LIBFT) $(SRCS1) -o$(NAME)
$(NAME2): $(LIBFT) $(INCLUDES) $(SRCS2)
	$(CC) $(FLAGS)  -I$(INCLUDES) $(LIBFT) $(SRCS2) -o$(NAME2)
$(LIBFT):
	@$(MAKE) -C lib/
%.o: %.c
	@$(CC) $(FLAGS) $< -o $@
clean:
	@$(MAKE) -C lib/ clean
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C lib/ fclean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
	# **************************************************************************** #

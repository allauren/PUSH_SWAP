# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allauren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 22:27:21 by allauren          #+#    #+#              #
#    Updated: 2017/12/14 19:49:46 by allauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS1 = insertion_sort.c doublelist.c list2del.c pushswapcommand.c \
		push_check.c push_swap.c utilspsw.c quicksort.c easy_split.c\
		utilpresort.c sort_small.c
SRCS2 = insertion_sort.c checker.c doublelist.c list2del.c pushswapcommand.c \
		push_check.c utilspsw.c quicksort.c utilpresort.c sort_small.c
CFLAGS =-g3 -c -Wall -Wextra -Werror
FLAGS  = -g3  -Wall -Wextra 
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

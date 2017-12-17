# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allauren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 22:27:21 by allauren          #+#    #+#              #
#    Updated: 2017/12/17 07:58:48 by allauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS1 = $(SRCREP)/doublelist.c $(SRCREP)/list2del.c $(SRCREP)/pushswapcommand.c\
		$(SRCREP)/push_check.c $(SRCREP)/push_swap.c $(SRCREP)/utilspsw.c\
		$(SRCREP)/quicksort.c $(SRCREP)/utilpresort.c $(SRCREP)/sort_small.c\
		$(SRCREP)/checkpsw.c $(SRCREP)/push_check2.c $(SRCREP)/short_sort.c \
		$(SRCREP)/smart_sort.c $(SRCREP)/ft_optimizer.c
SRCS2 = $(SRCREP)/checker.c $(SRCREP)/doublelist.c $(SRCREP)/list2del.c\
		$(SRCREP)/pushswapcommand.c $(SRCREP)/push_check.c $(SRCREP)/utilspsw.c\
		$(SRCREP)/quicksort.c $(SRCREP)/utilpresort.c $(SRCREP)/sort_small.c\
		$(SRCREP)/checkpsw.c $(SRCREP)/push_check2.c $(SRCREP)/ft_optimizer.c

INCLUDES = includes
CFLAGS = -c -Wall -Wextra -Werror -I$(INCLUDES) -Ilib
LFLAGS  = -L lib/ -lft
SRCREP = srcs
CC = gcc
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
NAME = push_swap
NAME2 = checker
LIBFT = lib/libft.a

all: $(NAME) $(NAME2)

$(NAME): $(LIBFT) $(INCLUDES) $(OBJS1)
	$(CC) $(LFLAGS) $(OBJS1) -o$(NAME)
$(NAME2): $(LIBFT) $(INCLUDES) $(OBJS2)
	$(CC) $(LFLAGS) $(OBJS2) -o$(NAME2)
$(LIBFT):
	@$(MAKE) -C lib/
$(SRCREP)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
clean:
	$(MAKE) -C lib/ clean
	rm -f $(OBJS2)
	rm -f $(OBJS1)

fclean: clean
	$(MAKE) -C lib/ fclean
	rm -f $(NAME)
	rm -f $(NAME2)
re: fclean all
.PHONY: all clean fclean re
# **************************************************************************** #

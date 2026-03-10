# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 13:05:44 by dabdulka          #+#    #+#              #
#    Updated: 2026/03/07 12:00:00 by dabdulka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -pthread

SRCS	= philosophers.c \
		  src/init_num.c \
		  src/philo_loop.c \
		  src/monitor.c \
		  src/utils.c	\
		  src/norm_hater.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

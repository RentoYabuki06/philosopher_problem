# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 00:34:53 by yabukirento       #+#    #+#              #
#    Updated: 2025/04/09 11:43:35 by ryabuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/main.c \
		./srcs/init.c \
		./srcs/free.c \
		./srcs/loop.c \
		./srcs/utils/atol.c \
		./srcs/utils/strncmp.c \
		./srcs/philo_utils/check_alldied.c \
		./srcs/philo_utils/print_status.c \

OBJS = $(SRCS:.c=.o)

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
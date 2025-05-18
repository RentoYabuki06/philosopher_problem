# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 00:33:18 by yabukirento       #+#    #+#              #
#    Updated: 2025/05/18 18:42:28 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/main.c \

OBJS = $(SRCS:.c=.o)

NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -lpthread -g
INCLUDES = -I./includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
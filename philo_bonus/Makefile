# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 00:33:18 by yabukirento       #+#    #+#              #
#    Updated: 2025/03/11 00:36:43 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./main.c \

OBJS = $(SRCS:.c=.o)

NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
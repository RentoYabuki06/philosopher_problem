# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 00:34:53 by yabukirento       #+#    #+#              #
#    Updated: 2025/04/22 14:32:33 by ryabuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/main.c \
		./srcs/init.c \
		./srcs/free.c \
		./srcs/eat.c \
		./srcs/monitor.c \
		./srcs/routine.c \
		./srcs/utils/atoi.c \
		./srcs/utils/strncmp.c \
		./srcs/utils/ft_isdigit.c \
		./srcs/philo_utils/get_time.c \
		./srcs/philo_utils/print_status.c \
		./srcs/philo_utils/flag_finish.c \

OBJS = $(SRCS:.c=.o)

NAME = philo
CC = gcc
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
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
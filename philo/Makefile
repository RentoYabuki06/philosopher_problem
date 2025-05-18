# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 00:34:53 by yabukirento       #+#    #+#              #
#    Updated: 2025/05/18 18:42:02 by yabukirento      ###   ########.fr        #
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
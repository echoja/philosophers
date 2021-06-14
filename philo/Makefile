# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 17:17:01 by taehokim          #+#    #+#              #
#    Updated: 2021/06/14 20:11:19 by taehokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = \
	resource.c \
	start.c \
	vars.c \
	init.c \
	time.c \
	put_msg.c \
	msg.c \
	die.c \
	philo_job.c \
	mutex.c \
	thread.c \
	watcher.c \
	main.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf
INC_DIR = -I./src
FLAGS = -Wall -Wextra -Werror
LIBS = -lpthread
CC = gcc

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@ $(INC_DIR) $(LIBS)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean
	$(MAKE) all

norm:
	find . -name "*.c" -o -name "*.h" | grep -v test | xargs norminette

.PHONY: all bonus clean fclean re norm test .c.o

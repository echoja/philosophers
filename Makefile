# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 17:17:01 by taehokim          #+#    #+#              #
#    Updated: 2021/06/11 08:51:34 by taehokim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
BONUS_NAME = philo_bonus

MAND_SRCS = \
	src/mand/resource.c \
	src/mand/start.c \
	src/mand/vars.c \
	src/mand/init.c \
	src/mand/time.c \
	src/mand/put_msg.c \
	src/mand/msg.c \
	src/mand/die.c \
	src/mand/philo_job.c \
	src/mand/mutex.c \
	src/mand/thread.c \
	src/mand/watcher.c \
	src/mand/main.c

BONUS_SRC = src/bonus/main.clean

OBJECTS = $(SOURCES:.c=.o)
MAND_OBJ = $(MAND_SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

RM = rm -rf
INC_DIR = -I./src
FLAGS = -Wall -Wextra -Werror -g
LIBS = -lpthread
CC = gcc

all: $(NAME)

$(MAND_OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

$(BONUS_OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

$(NAME): $(MAND_OBJ)
	$(CC) $(FLAGS) $^ -o $@ $(INC_DIR) $(LIBS)

checker: $(BONUS_OBJ)
	$(CC) $(FLAGS) $^ -o $@ $(INC_DIR) $(LIBS)

fclean: clean
	$(RM) $(NAME) test

clean:
	$(RM) $(MAND_OBJ) $(BONUS_OBJ) test.o

test: src/test.c
	$(CC) $(FLAGS) $^ -o $@ $(INC_DIR) $(LIBS)

re: fclean
	$(MAKE) all

norm:
	find . -name "*.c" -o -name "*.h" | grep -v test | xargs norminette

.PHONY: all bonus clean fclean re norm test .c.o

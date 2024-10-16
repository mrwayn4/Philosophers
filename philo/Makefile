# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 18:42:09 by ibouram           #+#    #+#              #
#    Updated: 2024/10/16 18:50:10 by ibouram          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo.c philo_utils.c init.c routine.c monitor.c

RM = rm -rf
NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror

SRCO = $(SRC:.c=.o)

all: $(NAME)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "DONE"
$(NAME): $(SRCO)
	@$(CC) $(FLAGS) $^ -o $@

%.o: %.c philo.h
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(SRCO)

fclean: clean
	@$(RM) $(NAME)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Clean"

re: fclean all
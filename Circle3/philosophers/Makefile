# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 17:35:05 by jahlee            #+#    #+#              #
#    Updated: 2023/05/25 15:14:02 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= philo
CC			= @cc
CFLAGS		= -Wall -Wextra -Werror -pthread
RM			= @rm
RMFLAGS		= -f
INCLUDES	= ./includes/philo.h

# color
RESET		= \033[0m
GREEN		= \033[1;92m
MAGENTA		= \033[1;95m

SRCS		= ./srcs/main.c			\
			  ./srcs/init.c			\
			  ./srcs/utils.c		\
			  ./srcs/thread.c		\
			  ./srcs/check_status.c	\

OBJS		= $(SRCS:.c=.o)

REALOBJS 	= $(OBJS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "$(MAGENTA)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(MAGENTA)║                                               ║$(RESET)"
	@echo "$(MAGENTA)║                 philosophers                  ║$(RESET)"
	@echo "$(MAGENTA)║               compile finished.               ║$(RESET)"
	@echo "$(MAGENTA)║                                               ║$(RESET)"
	@echo "$(MAGENTA)╚═══════════════════════════════════════════════╝$(RESET)"

clean:
	$(RM) $(RMFLAGS) $(OBJS)
	@echo "$(GREEN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║              make clean finished.             ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════════════════════════╝$(RESET)"

fclean:
	@make clean
	$(RM) $(RMFLAGS) $(NAME)
	@echo "$(GREEN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║             make fclean finished.             ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════════════════════════╝$(RESET)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 17:35:05 by jahlee            #+#    #+#              #
#    Updated: 2023/05/14 14:54:18 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= philosophers
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= @rm
RMFLAGS		= -f

# color
RESET	= \033[0m
GREEN	= \033[1;92m
CYAN	= \033[1;96m
MAGENTA	= \033[1;95m

SRCS		= ./philo/srcs/philosophers.c

INCLUDES	= ./philo/includes/philosophers.h

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef BONUS_ON
    REALOBJS = $(OBJS_BONUS)
	INCLUDES = ./philo/includes/philosophers_bonus.h
else
    REALOBJS = $(OBJS)
endif

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "$(MAGENTA)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(MAGENTA)║                                               ║$(RESET)"
	@echo "$(MAGENTA)║                 philosophers                  ║$(RESET)"
	@echo "$(MAGENTA)║               compile finished.               ║$(RESET)"
	@echo "$(MAGENTA)║                                               ║$(RESET)"
	@echo "$(MAGENTA)╚═══════════════════════════════════════════════╝$(RESET)"

clean:
	$(RM) $(OBJS)
	@echo "$(GREEN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║              make clean finished.             ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════════════════════════╝$(RESET)"

fclean:
	@make clean
	$(RM) $(NAME)
	@echo "$(GREEN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║             make fclean finished.             ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════════════════════════╝$(RESET)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re

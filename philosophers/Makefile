# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 17:35:05 by jahlee            #+#    #+#              #
#    Updated: 2023/05/13 16:28:14 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= philosophers
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= @rm
RMFLAGS		= -f
AR			= @ar
ARFLAGS		= -crs

# color
RESET	= \033[0m
GREEN	= \033[1;92m
CYAN	= \033[1;96m
MAGENTA	= \033[1;95m

SRCS		= main.c \

INCLUDES	= ./includes/pipex.h

SRCS_BONUS	= \

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef BONUS_ON
    REALOBJS = $(OBJS_BONUS)
	INCLUDES = ./includes/pipex_bonus.h
else
    REALOBJS = $(OBJS)
endif

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT) $^ -o -I $(NAME)
	@echo "$(MAGENTA)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(MAGENTA)║                                               ║$(RESET)"
	@echo "$(MAGENTA)║                 philosophers                  ║$(RESET)"
	@echo "$(MAGENTA)║               compile finished.               ║$(RESET)"
	@echo "$(MAGENTA)║                                               ║$(RESET)"
	@echo "$(MAGENTA)╚═══════════════════════════════════════════════╝$(RESET)"

clean:
	@$(RM) $(MS_OBJS)
	@echo "$(GREEN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║              make clean finished.             ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════════════════════════╝$(RESET)"

fclean:
	@make clean
	@$(RM) $(NAME)
	@echo "$(GREEN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║             make fclean finished.             ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════════════════════════╝$(RESET)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re

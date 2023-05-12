# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 17:35:05 by jahlee            #+#    #+#              #
#    Updated: 2023/05/12 17:41:09 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= philosophers
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# color
RESET	= \033[0m
GREEN	= \033[1;92m
CYAN	= \033[1;96m
MAGENTA	= \033[1;95m

SRCS		= main.c \
			  $(LEXICAL) \
			  $(SYNTAX) \
			  $(CMD_LIST) \
			  $(BUILT_IN) \
			  $(EXCUTE) \
			  $(UTILS)

PATH		= $(addprefix $(MS_DIR), $(MS_SRCS))
OBJS		= $(MS_PATH:c=o)

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT) $^ -o $(NAME)
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

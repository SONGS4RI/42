# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 16:44:10 by jahlee            #+#    #+#              #
#    Updated: 2023/07/04 15:17:45 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex03

# compile option
CXX			= @c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# remove option
RM			= @rm
RMFLAGS		= -f

# color
RESET		= \033[0m
GREEN		= \033[1;92m
MAGENTA		= \033[1;95m

SRCS		= 	main.cpp		\
				Weapon.cpp		\
				HumanA.cpp		\
				HumanB.cpp		\

OBJS	= $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$(GREEN)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)║               compile finished.               ║$(RESET)"
	@echo "$(GREEN)║                                               ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════════════════════════╝$(RESET)"

clean :
	$(RM) $(RMFLAGS) $(OBJS)
	@echo "$(MAGENTA)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(MAGENTA)║                                               ║$(RESET)"
	@echo "$(MAGENTA)║               clean finished.                 ║$(RESET)"
	@echo "$(MAGENTA)║                                               ║$(RESET)"
	@echo "$(MAGENTA)╚═══════════════════════════════════════════════╝$(RESET)"

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
	@echo "$(MAGENTA)╔═══════════════════════════════════════════════╗$(RESET)"
	@echo "$(MAGENTA)║                                               ║$(RESET)"
	@echo "$(MAGENTA)║               fclean finished.                ║$(RESET)"
	@echo "$(MAGENTA)║                                               ║$(RESET)"
	@echo "$(MAGENTA)╚═══════════════════════════════════════════════╝$(RESET)"

re : clean all

.PHONY : all clean fclean re
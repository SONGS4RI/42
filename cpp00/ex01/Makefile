# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 16:44:10 by jahlee            #+#    #+#              #
#    Updated: 2023/06/20 16:55:21 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= @c++
CFLAG		= -Wall -Wextra -Werror -std=c++98

RM			= @rm
RMFLAGS		= -f

INCLUDES	= 

SRCS		= 

OBJS	= $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(NAME) : $(OBJS)
	$(CC) $(MLXFLAG) $(CFLAGS) $^ $(LIBFTFILE2) -o $@ -I $(INCLUDES)

all : $(NAME)

clean :
	@make -C $(LIBFTDIR) clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@make -C $(LIBFTDIR) fclean
	$(RM) $(RMFLAGS) $(LIBFTFILE2) $(NAME)

re : clean all

.PHONY : all clean fclean re
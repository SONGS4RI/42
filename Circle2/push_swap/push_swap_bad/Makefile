# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 16:28:17 by jahlee            #+#    #+#              #
#    Updated: 2023/02/15 20:46:53 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a
LIBFTFILE2	= libft_push_swap.a

CC			= @cc
CFLAG		= -Wall -Wextra -Werror

RM			= @rm
RMFLAGS		= -f
AR			= @ar
ARFLAGS		= -crs

INCLUDES	= ./includes/push_swap.h

SRCS		= srcs/ps_main.c			\
			  srcs/ps_utils.c			\
			  srcs/split_to_stack.c		\
			  srcs/pop_push.c			\
			  srcs/command.c			\
			  srcs/ps_algorithm.c		\

OBJS	= $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(NAME) : $(OBJS)
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTFILE) $(LIBFTFILE2)
	$(CC) $(CFLAGS) $^ $(LIBFTFILE2) -o $@ -I $(INCLUDES)

all : $(NAME)

clean :
	@make -C $(LIBFTDIR) clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@make -C $(LIBFTDIR) fclean
	$(RM) $(RMFLAGS) $(LIBFTFILE2) $(NAME)

re : clean all

.PHONY : all clean fclean re
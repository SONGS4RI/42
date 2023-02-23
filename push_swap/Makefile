# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 16:28:17 by jahlee            #+#    #+#              #
#    Updated: 2023/02/23 17:05:15 by jahlee           ###   ########.fr        #
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

SRCS		= srcs/ps_main.c					\
			  srcs/ps_utils.c					\
			  srcs/ps_split_to_stack.c			\
			  srcs/ps_pop_push.c				\
			  srcs/ps_command.c					\
			  srcs/ps_algorithm.c				\
			  srcs/ps_a_to_b.c					\
			  srcs/ps_b_to_a.c					\

SRCS_BONUS	= bonus/get_next_line.c				\
			  bonus/get_next_line_utils.c		\
			  bonus/ps_command_bonus.c			\
			  bonus/ps_do_command.c				\
			  bonus/ps_main_bonus.c				\
			  bonus/ps_pop_push_bonus.c			\
			  bonus/ps_split_to_stack_bonus.c	\
			  bonus/ps_utils_bonus.c			\

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef BONUS_ON
    REALOBJS = $(OBJS_BONUS)
	NAME = checker
	INCLUDES = ./includes/push_swap_bonus.h
else
    REALOBJS = $(OBJS)
endif

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(NAME) : $(REALOBJS)
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTFILE) $(LIBFTFILE2)
	$(CC) $(CFLAGS) $^ $(LIBFTFILE2) -o $@ -I $(INCLUDES)

all : $(NAME)

bonus :
	@make BONUS_ON=1

clean :
	@make -C $(LIBFTDIR) clean
	$(RM) $(RMFLAGS) $(REALOBJS) $(OBJS_BONUS)

fclean : clean
	@make -C $(LIBFTDIR) fclean
	$(RM) $(RMFLAGS) $(LIBFTFILE2) checker push_swap

re : clean all

.PHONY : all bonus clean fclean re
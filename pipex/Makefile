# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 16:28:17 by jahlee            #+#    #+#              #
#    Updated: 2023/03/15 20:03:39 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

CC			= @cc
CFLAG		= -Wall -Wextra -Werror

RM			= @rm
RMFLAGS		= -f
AR			= @ar
ARFLAGS		= -crs

INCLUDES	= ./includes/pipex.h

SRCS		= srcs/px_main.c			\
			  srcs/px_parse.c			\
			  srcs/px_util.c			\


SRCS_BONUS	= bonus/px_main_bonus.c			\
			  bonus/px_parse_bonus.c		\
			  bonus/px_util_bonus.c			\
			  bonus/px_setfd_bonus.c		\

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef BONUS_ON
    REALOBJS = $(OBJS_BONUS)
	INCLUDES = ./includes/pipex_bonus.h
	NAME = pipex_bonus
else
    REALOBJS = $(OBJS)
endif

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(NAME) : $(REALOBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $^ $(LIBFTDIR)/$(LIBFTFILE) -o $@ -I $(INCLUDES)

all : $(NAME)

bonus :
	@make BONUS_ON=1

clean :
	@make -C $(LIBFTDIR) clean
	$(RM) $(RMFLAGS) $(REALOBJS) $(OBJS_BONUS)

fclean : clean
	@make -C $(LIBFTDIR) fclean
	$(RM) $(RMFLAGS) $(LIBFTFILE2) pipex pipex_bonus

re : clean all

.PHONY : all bonus clean fclean re
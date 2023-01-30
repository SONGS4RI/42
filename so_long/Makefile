# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 16:28:17 by jahlee            #+#    #+#              #
#    Updated: 2023/01/30 16:13:02 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long.a
# LIBFTDIR	= ./libft
LIBFTDIR	= libft
LIBFTFILE	= libft.a

CC			= @cc
CFLAG		= -Wall -Wextra -Werror

RM			= @rm
RMFLAGS		= -f
AR			= @ar
ARFLAGS		= -crs

INCLUDES	= ../so_long.h
# INCLUDES	= ./so_long.h

SRCS		= main.c		\
			  parse_map.c	\
			  

OBJS	= $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(NAME) : $(OBJS)
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	$(AR) $(ARFLAGS) $@ $^

all : $(NAME)

clean :
	@make -C $(LIBFTDIR) clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@make -C $(LIBFTDIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : clean all

.PHONY : all clean fclean re
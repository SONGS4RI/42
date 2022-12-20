# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 14:08:23 by jahlee            #+#    #+#              #
#    Updated: 2022/12/20 18:22:29 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_printf.a

CC			= @cc
CFLAG		= -Wall -Wextra -Werror

RM			= @rm
RMFLAG		= -f
AR			= @ar
ARFLAGS		= crs

INCLUDES	= ./ft_printf.h

SRCS		=

SRCS_BONUS	=

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(INCLUDES)

ifdef BONUS_ON
    REALOBJS = $(OBJS) $(OBJS_BONUS)
else
    REALOBJS = $(OBJS)
endif

$(NAME) : $(REALOBJS)
	$(AR) $(ARFLAGS) $@ $^

all : $(NAME)

clean :
	$(RM) $(RMFLAG) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

bonus :
	@make BONUS_ON=1

 .PHONY : all clean fclean re bonus

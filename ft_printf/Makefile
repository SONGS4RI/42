# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 14:08:23 by jahlee            #+#    #+#              #
#    Updated: 2022/12/28 16:19:11 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_printf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

CC			= @cc
CFLAG		= -Wall -Wextra -Werror

RM			= @rm
RMFLAGS		= -f
AR			= @ar
ARFLAGS		= -crs

INCLUDES	= ./ft_printf.h

SRCS		= ft_printf.c		\
			  ft_printf_c.c		\
			  ft_printf_s.c		\
			  ft_printf_p.c		\
			  ft_printf_di.c	\
			  ft_printf_u.c		\
			  ft_printf_hex.c	\

OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I $(INCLUDES)

$(NAME) : $(OBJS)
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	$(AR) $(ARFLAGS) $@ $?

all : $(NAME)

clean :
	@make -C $(LIBFTDIR) clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@make -C $(LIBFTDIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : clean all

.PHONY : all clean fclean re
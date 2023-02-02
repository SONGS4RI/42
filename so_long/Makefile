# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 16:28:17 by jahlee            #+#    #+#              #
#    Updated: 2023/02/02 16:00:56 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a
LIBFTFILE2	= libft_so_long.a

CC			= @cc
CFLAG		= -Wall -Wextra -Werror
MLXFLAG		= -lmlx -framework OpenGL -framework AppKit

RM			= @rm
RMFLAGS		= -f
AR			= @ar
ARFLAGS		= -crs

INCLUDES	= ./so_long.h

SRCS		= main.c			\
			  parse_map.c		\
			  free_func.c		\
			  check_map_1.c		\
			  check_map_2.c		\
			  map_to_window.c	\

OBJS	= $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(NAME) : $(OBJS)
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTFILE) $(LIBFTFILE2)
	$(CC) $(MLXFLAG) $(CFLAGS) $^ $(LIBFTFILE2) -o $@

all : $(NAME)

clean :
	@make -C $(LIBFTDIR) clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@make -C $(LIBFTDIR) fclean
	$(RM) $(RMFLAGS) $(LIBFTFILE2) $(NAME)

re : clean all

.PHONY : all clean fclean re
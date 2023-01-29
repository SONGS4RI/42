# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 14:08:23 by jahlee            #+#    #+#              #
#    Updated: 2023/01/29 16:28:26 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= @cc
CFLAG		= -Wall -Wextra -Werror

RM			= @rm
RMFLAG		= -f
AR			= @ar
ARFLAGS		= crs

INCLUDES	= ../libft.h
# INCLUDES	= ./libft.h

SRCS_1		= ft_isalpha.c		\
			  ft_isdigit.c		\
			  ft_isalnum.c		\
			  ft_isascii.c		\
			  ft_isprint.c		\
			  ft_strlen.c		\
			  ft_memset.c		\
			  ft_bzero.c		\
			  ft_memcpy.c		\
			  ft_memmove.c		\
			  ft_strlcpy.c		\
			  ft_strlcat.c		\
			  ft_toupper.c		\
			  ft_tolower.c		\
			  ft_strchr.c		\
			  ft_strrchr.c		\
			  ft_strncmp.c		\
			  ft_memchr.c		\
			  ft_memcmp.c		\
			  ft_strnstr.c 		\
			  ft_atoi.c 		\
			  ft_calloc.c 		\
			  ft_strdup.c 		\

SRCS_2	=     ft_substr.c 		\
			  ft_strjoin.c 		\
			  ft_strtrim.c 		\
			  ft_split.c 		\
			  ft_itoa.c 		\
			  ft_strmapi.c 		\
			  ft_striteri.c 	\
			  ft_putchar_fd.c 	\
			  ft_putstr_fd.c 	\
			  ft_putendl_fd.c	\
			  ft_putnbr_fd.c 	\

SRCS_BONUS =  ft_lstnew.c 		\
			  ft_lstadd_front.c	\
			  ft_lstsize.c 		\
			  ft_lstlast.c 		\
			  ft_lstadd_back.c 	\
			  ft_lstdelone.c 	\
			  ft_lstclear.c 	\
			  ft_lstiter.c 		\
			  ft_lstmap.c 		\

SRCS	= $(SRCS_1)			\
	 	  $(SRCS_2)			\

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

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

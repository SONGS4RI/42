# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 14:08:23 by jahlee            #+#    #+#              #
#    Updated: 2023/03/10 20:28:29 by jahlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= @cc
CFLAG		= -Wall -Wextra -Werror

RM			= @rm
RMFLAG		= -f
AR			= @ar
ARFLAGS		= crs

INCLUDES	= ./libft.h

SRCS_1		= srcs/libft_origin/ft_isalpha.c		\
			  srcs/libft_origin/ft_isdigit.c		\
			  srcs/libft_origin/ft_isalnum.c		\
			  srcs/libft_origin/ft_isascii.c		\
			  srcs/libft_origin/ft_isprint.c		\
			  srcs/libft_origin/ft_strlen.c			\
			  srcs/libft_origin/ft_memset.c			\
			  srcs/libft_origin/ft_bzero.c			\
			  srcs/libft_origin/ft_memcpy.c			\
			  srcs/libft_origin/ft_memmove.c		\
			  srcs/libft_origin/ft_strlcpy.c		\
			  srcs/libft_origin/ft_strlcat.c		\
			  srcs/libft_origin/ft_toupper.c		\
			  srcs/libft_origin/ft_tolower.c		\
			  srcs/libft_origin/ft_strchr.c			\
			  srcs/libft_origin/ft_strrchr.c		\
			  srcs/libft_origin/ft_strncmp.c		\
			  srcs/libft_origin/ft_memchr.c			\
			  srcs/libft_origin/ft_memcmp.c			\
			  srcs/libft_origin/ft_strnstr.c 		\
			  srcs/libft_origin/ft_atoi.c 			\
			  srcs/libft_origin/ft_calloc.c 		\
			  srcs/libft_origin/ft_strdup.c 		\

SRCS_2		= srcs/libft_origin/ft_substr.c 		\
			  srcs/libft_origin/ft_strjoin.c 		\
			  srcs/libft_origin/ft_strtrim.c 		\
			  srcs/libft_origin/ft_split.c 			\
			  srcs/libft_origin/ft_itoa.c 			\
			  srcs/libft_origin/ft_strmapi.c 		\
			  srcs/libft_origin/ft_striteri.c 		\
			  srcs/libft_origin/ft_putchar_fd.c 	\
			  srcs/libft_origin/ft_putstr_fd.c 		\
			  srcs/libft_origin/ft_putendl_fd.c		\
			  srcs/libft_origin/ft_putnbr_fd.c 		\

SRCS_3		= srcs/additional/ft_pipex_split.c 		\

FT_PRINTF 	= srcs/ft_printf/ft_printf_c.c			\
			  srcs/ft_printf/ft_printf_di.c			\
			  srcs/ft_printf/ft_printf_hex.c		\
			  srcs/ft_printf/ft_printf_p.c			\
			  srcs/ft_printf/ft_printf_s.c			\
			  srcs/ft_printf/ft_printf_u.c			\
			  srcs/ft_printf/ft_printf.c			\

GNL			= srcs/gnl/get_next_line_utils.c			\
			  srcs/gnl/get_next_line.c				\

SRCS	= $(SRCS_1)			\
	 	  $(SRCS_2)			\
		  $(SRCS_3)			\
		  $(FT_PRINTF)		\
		  $(GNL)			\

OBJS	= $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(INCLUDES)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

all : $(NAME)

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

 .PHONY : all clean fclean re

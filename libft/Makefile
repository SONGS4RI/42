NAME		= libft.a

CC			= @gcc
CFLAG		= -Wall -Wextra -Werror

RM			= @rm
RMFLAG		= -f
AR			= @ar
ARFLAGS		= crs

INCLUDES	= ./libft.h 

SRCS_1		= ft_isalpha.c		\
			  ft_isdigit.c		\
			  ft_isalnum.c		\
			  ft_isaascii.c		\
			  ft_isprint.c		\
			  ft_strlen.c		\
			  ft_memset.c		\
			  ft_bzero.c		\
			  ft_memcpy.c		\
			  ft_memmove.c		\
			  ft_strlcpy.c		\
			  

SRCS_2	=     

SRCS_BN =     

SRCS	= $(SRCS_1)			\
	 	  $(SRCS_2)			\

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BN:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(RMFLAG) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus : $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $^

 .PHONY : all clean fclean re

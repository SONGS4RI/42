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

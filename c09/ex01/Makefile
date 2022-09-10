NAME = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

INC = includes/ft.h

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

all : $(NAME)
 
$(NAME) : $(OBJS)
			ar -crus $@ $^
%.o: %.c
		$(CC) $(CFLAGS) $< -o $@ -I $(INC)
clean :
		rm -rf $(OBJS)
fclean : clean
		rm -rf $(NAME)
re : fclean all

.PHONY : all clean fclean re

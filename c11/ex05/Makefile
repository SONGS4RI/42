NAME = do-op

SRCS =  main.c atoi.c ft_putnbr.c op_idx.c op.c
OBJS = $(SRCS:.c=.o)

CC = @gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGSC = -c -Wall -Wextra -Werror

all : $(NAME)
 
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o: %.c
		$(CC) $(CFLAGSC) $< -o $@

clean :
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
